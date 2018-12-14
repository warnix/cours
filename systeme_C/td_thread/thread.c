#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>

#define TIME_DIFF(t1, t2)\
((t2.tv_sec - t1.tv_sec)*1000000 + (t2.tv_usec - t1.tv_usec))
#define TAILLE_TAB 2000000

void *say_hello(void* data){
    char *str;
    str = (char*)data;
    while(1)
    {
        printf("%s\n",str);
        break;
    }
}
struct agrs_somme_tranche{
    float *tableau;
    int debut, fin;
    float *adr_somme;
};

float somme_tranche(float tableau[], int debut, int fin){
    float somme = 0;
    for(int i= debut; i<fin; i++){
        somme += tableau[i];
    }
    return somme;
}

void *thread_somme_tranche(void *args){
    struct agrs_somme_tranche *a=args;
    * (a->adr_somme) = somme_tranche(a->tableau,a->debut,a->fin);
    return NULL;
}

void remplir_tableau(float *tableau){
    for(int i = 0; i<TAILLE_TAB; i++){
        tableau[i]=i%2;
    }
}

void calcul(){
    float *tableau = malloc(TAILLE_TAB * sizeof(float));
    remplir_tableau(tableau);
    float somme = somme_tranche(tableau,0,TAILLE_TAB);
    printf("la somme du tableau est : %f\n",somme);
}

void calcul1(){
    float *tableau = malloc(TAILLE_TAB * sizeof(float));
    remplir_tableau(tableau);
    float somme;
    struct agrs_somme_tranche
    agrs={tableau,0,TAILLE_TAB, &somme};
    pthread_t t;
    pthread_create(&t,NULL,thread_somme_tranche,&agrs);
    pthread_join(t,NULL);
    printf("la somme du tableau est : %f\n",somme);
}

void calcul2(){
    float *tableau = malloc(TAILLE_TAB * sizeof(float));
    remplir_tableau(tableau);
    float somme1, somme2;
    struct agrs_somme_tranche
    agrs1={tableau,0,TAILLE_TAB/2, &somme1},
    agrs2={tableau,TAILLE_TAB/2,TAILLE_TAB, &somme2};
    pthread_t t3,t4;
    pthread_create(&t3,NULL,thread_somme_tranche, &agrs1);
    pthread_create(&t4,NULL,thread_somme_tranche, &agrs2);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    printf("la somme du tableau est : %f + %f = %f\n",somme1,somme2,(somme1+somme2));
}

void calcul4(){
    float *tableau = malloc(TAILLE_TAB * sizeof(float));
    remplir_tableau(tableau);
    float somme1, somme2, somme3, somme4;
    struct agrs_somme_tranche
    agrs1={tableau,0,TAILLE_TAB/4, &somme1},
    agrs2={tableau,TAILLE_TAB/4,TAILLE_TAB/2, &somme2},
    agrs3={tableau,TAILLE_TAB/2,(TAILLE_TAB/4)*3, &somme3},
    agrs4={tableau,(TAILLE_TAB/4)*3,TAILLE_TAB, &somme4};
    pthread_t t1,t2,t3,t4;
    pthread_create(&t1,NULL,thread_somme_tranche, &agrs1);
    pthread_create(&t2,NULL,thread_somme_tranche, &agrs2);
    pthread_create(&t3,NULL,thread_somme_tranche, &agrs3);
    pthread_create(&t4,NULL,thread_somme_tranche, &agrs4);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    printf("la somme du tableau est : %f + %f + %f + %f = %f\n",somme1,somme2,somme3,somme4,(somme1+somme2+somme3+somme4));
}

void all_calcul(){
    struct timeval tv1, tv2;
    gettimeofday(&tv1,NULL);
    calcul();
    gettimeofday(&tv2,NULL);
    printf("durée de calcul (no thread) : %f ms\n",((float)TIME_DIFF(tv1,tv2)/1000));

    sleep(1);

    gettimeofday(&tv1,NULL);
    calcul1();
    gettimeofday(&tv2,NULL);
    printf("durée de calcul (1 thread) : %f ms\n",((float)TIME_DIFF(tv1,tv2)/1000));

    sleep(1);

    gettimeofday(&tv1,NULL);
    calcul2();
    gettimeofday(&tv2,NULL);
    printf("durée de calcul (2 thread) : %f ms\n",((float)TIME_DIFF(tv1,tv2)/1000));

    sleep(1);

    gettimeofday(&tv1,NULL);
    calcul4();
    gettimeofday(&tv2,NULL);
    printf("durée de calcul (4 thread) : %f ms\n",((float)TIME_DIFF(tv1,tv2)/1000));
}

int main(void){
    pthread_t th1,th2;
    pthread_create(&th1, NULL, say_hello, "hello from thread 1");
    sleep(1);
    pthread_create(&th2, NULL, say_hello, "hello from thread 2");
    pthread_join(th1,NULL);
    pthread_join(th2 ,NULL);

    int i = 0;
    while(i<10){
        all_calcul();
        i++;
    }
}