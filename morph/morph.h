#ifndef MORPH_H
#define MORPH_H

#ifndef STDDEF_H
#define NULL ((void *)0)
#endif

#define NONE "no equivalent"

#define DESC_NUM 25
#define DESC_LEN 250

struct Pointers {
	char *word;
	char (*descs)[DESC_LEN];
	int i;
	int j;
};

extern char *verb_endings[];
extern char *suffixes[];
extern char *prefixes[];

void check_endings(struct Pointers *);

#endif
