CC = gcc
CFLAGS = -D_XOPEN_SOURCE=700 -Wno-unused-parameter -std=c11 -Wall -Wextra -pedantic

all: main
main:main.o StringVector.o shell.o commands.o
main.o: StringVector.h shell.h commands.h
StringVector.o: StringVector.h
shell.o: shell.h 
commands.o: commands.h 