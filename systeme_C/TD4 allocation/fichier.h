#ifndef FICHIER_H
#define FICHIER_H
int lire_fichier(struct Annuaire *ptr_annuaire, const char *nomfic);
int ecrire_fichier(const struct Annuaire *ptr_annuaire, const char *nomfic);
#endif