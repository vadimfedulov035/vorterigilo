#ifndef MORPH_H
#define MORPH_H

#ifndef STDDEF_H
#define NULL ((void *)0)
#endif

#define DEF_NUM 14
#define DEF_LEN 250

extern char *roots[];
extern char *postfixes[];
extern char *prefixes[];

#include "../hashmap/hashmap.h"
#include "../vocab/vocab.h"

bool check_full(char *word, char (*defs)[DEF_LEN], int i, Map *map);
char *check_end(char *pword, char (*defs)[DEF_LEN], int i);
char *check_f(char *word, char (*defs)[DEF_LEN], int i, Map *map);
char *check_b(char *pword, char *word, char (*defs)[DEF_LEN], int i, Map *map);

#define BRO2 "2"
#define BRO3 "3"
#define BRO4 "4"
#define BRO5 "5"
#define BRO6 "6"
#define BRO7 "7"
#define BRO8 "8"
#define BRO9 "9"
#define OA10 "10"

#define N_ROOT "0"
#define V_ROOT "1"
#define A_ROOT "2"
#define B_ROOT "3"

#define NATION "nation"

#define NONE "no equivalent"

#endif
