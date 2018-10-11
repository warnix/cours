CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic

all: main
main:main.o StringVector.o shell.o
main.o: StringVector.h shell.h
StringVector.o: StringVector.h
shell.o:shell.h