#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>

#define TIME_DIFF(t1, t2) \
    ((t2.tv_sec - t1.tv_sec) * 1000000 + (t2.tv_usec - t1.tv_usec))
#define TAILLE_TAB 2000000

void *say_hello(void *data)
{
    char *str;
    str = (char *)data;
    while (1)
    {
        printf("%s\n", str);
        break;
    }
}
struct agrs_somme_tranche
{
    float *tableau;
    int debut, fin;
    float *adr_somme;
    pthread_mutex_t *mutex;
};

void somme_tranche(float tableau[], int debut, int fin, float *s, pthread_mutex_t *mutex)
{
    float tmp = 0.;
    for (int i = debut; i < fin; i++)
    {
        tmp += tableau[i];
    }
    pthread_mutex_lock(mutex);
    *s += tmp;
    pthread_mutex_unlock(mutex);
}

void *thread_somme_tranche(void *args)
{
    struct agrs_somme_tranche *a = args;
    somme_tranche(a->tableau, a->debut, a->fin, a->adr_somme, a->mutex);
    return NULL;
}

void remplir_tableau(float *tableau)
{
    for (int i = 0; i < TAILLE_TAB; i++)
    {
        tableau[i] = i % 2;
    }
}

void calcul(float somme, pthread_mutex_t mutex)
{
    float *tableau = malloc(TAILLE_TAB * sizeof(float));
    remplir_tableau(tableau);
    somme_tranche(tableau, 0, TAILLE_TAB, &somme, &mutex);
    printf("la somme du tableau est : %f\n", somme);
}

void calcul1(float somme, pthread_mutex_t mutex)
{
    float *tableau = malloc(TAILLE_TAB * sizeof(float));
    remplir_tableau(tableau);
    struct agrs_somme_tranche
        agrs = {tableau, 0, TAILLE_TAB, &somme, &mutex};
    pthread_t t;
    pthread_create(&t, NULL, thread_somme_tranche, &agrs);
    pthread_join(t, NULL);
    printf("la somme du tableau est : %f\n", somme);
}

void calcul2(float somme, pthread_mutex_t mutex)
{
    float *tableau = malloc(TAILLE_TAB * sizeof(float));
    remplir_tableau(tableau);
    struct agrs_somme_tranche
        agrs1 = {tableau, 0, TAILLE_TAB / 2, &somme, &mutex},
        agrs2 = {tableau, TAILLE_TAB / 2, TAILLE_TAB, &somme, &mutex};
    pthread_t t3, t4;
    pthread_create(&t3, NULL, thread_somme_tranche, &agrs1);
    pthread_create(&t4, NULL, thread_somme_tranche, &agrs2);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    printf("la somme du tableau est : %f\n", somme);
}

void calcul4(float somme, pthread_mutex_t mutex)
{
    float *tableau = malloc(TAILLE_TAB * sizeof(float));
    remplir_tableau(tableau);
    struct agrs_somme_tranche
        agrs1 = {tableau, 0, TAILLE_TAB / 4, &somme, &mutex},
        agrs2 = {tableau, TAILLE_TAB / 4, TAILLE_TAB / 2, &somme, &mutex},
        agrs3 = {tableau, TAILLE_TAB / 2, (TAILLE_TAB / 4) * 3, &somme, &mutex},
        agrs4 = {tableau, (TAILLE_TAB / 4) * 3, TAILLE_TAB, &somme, &mutex};
    pthread_t t1, t2, t3, t4;
    pthread_create(&t1, NULL, thread_somme_tranche, &agrs1);
    pthread_create(&t2, NULL, thread_somme_tranche, &agrs2);
    pthread_create(&t3, NULL, thread_somme_tranche, &agrs3);
    pthread_create(&t4, NULL, thread_somme_tranche, &agrs4);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    printf("la somme du tableau est : %f\n", somme);
}

void all_calcul()
{
    struct timeval tv1, tv2;
    float somme = 0.;
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);
    gettimeofday(&tv1, NULL);
    calcul(somme, mutex);
    gettimeofday(&tv2, NULL);
    printf("durée de calcul (no thread) : %f ms\n", ((float)TIME_DIFF(tv1, tv2) / 1000));

    sleep(1);

    gettimeofday(&tv1, NULL);
    calcul1(somme, mutex);
    gettimeofday(&tv2, NULL);
    printf("durée de calcul (1 thread) : %f ms\n", ((float)TIME_DIFF(tv1, tv2) / 1000));

    sleep(1);

    gettimeofday(&tv1, NULL);
    calcul2(somme, mutex);
    gettimeofday(&tv2, NULL);
    printf("durée de calcul (2 thread) : %f ms\n", ((float)TIME_DIFF(tv1, tv2) / 1000));

    sleep(1);

    gettimeofday(&tv1, NULL);
    calcul4(somme, mutex);
    gettimeofday(&tv2, NULL);
    printf("durée de calcul (4 thread) : %f ms\n", ((float)TIME_DIFF(tv1, tv2) / 1000));
}

int main(void)
{
    pthread_t th1, th2;
    pthread_create(&th1, NULL, say_hello, "hello from thread 1");
    sleep(1);
    pthread_create(&th2, NULL, say_hello, "hello from thread 2");
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    int i = 0;
    while (i < 10)
    {
        printf("----%d----\n",i);
        all_calcul();
        i++;
    }
}