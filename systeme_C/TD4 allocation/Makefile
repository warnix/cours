CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic

all: manipFichier
manipFichier: manipFichier.o annuaire.o fichier.o
manipFichier.o : fichier.h
annuaire.o : annuaire.h
fichier.o : fichier.h
