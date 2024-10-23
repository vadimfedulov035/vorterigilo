#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "hashmap/hashmap.h"
#include "vocab/vocab.h"

#include "base/base.h"
#include "morph/morph.h"


void tolower_diacritic(char *str, int *idx) {
	/* diacritic letters are represesented
	 * by two contiguous bytes, we increment:
	 * the second byte to make letter lowercase,
	 * the index to get to the next letter */

	unsigned char *fir = (unsigned char *) str;
	unsigned char *sec = fir + 1;
	switch (*fir) {
		case 196:
			switch (*sec) {
				case 136:  // Ĉ
				case 156:  // Ĝ
				case 180:  // Ĵ
					(*sec)++;
					(*idx)++;
					break;
				default:
					break;
			}
			break;
		case 197:
			switch (*sec) {
				case 156:  // Ŝ
				case 164:  // Ĥ
				case 172:  // Ŭ
					(*sec)++;
					(*idx)++;
					break;
				default:
					break;
			}
		default:
			break;
	}
}

void tolower_eo(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        // convert standard letters to lowercase
        str[i] = tolower(str[i]);

		// convert diacritic letters to lowercase
		tolower_diacritic(str, &i);
    }
}

void read_defs(char (*defs)[DEF_LEN]) {
	bool is_read = false;
	for (int i = 0; i < DEF_NUM; i++) {
		if (strcmp(defs[i], "") != 0) {
			is_read = true;
			printf("%s, ", defs[i]);
		}
	}
	if (is_read) {
		printf("\b\b \n");
	}
}

void clear_defs(char (*defs)[DEF_LEN]) {
	// clean definitions
	for (int i = 0; i < DEF_NUM; i++) {
		strcpy(defs[i], "");
	}
}

void analyze(char *line, char (*defs)[DEF_LEN], Maps *maps) {
	// get maps for analysis
	Map *base_map = maps->base_map;
	Map *root_map = maps->root_map;
	Map *pre_map  = maps->pre_map;
	Map *post_map = maps->post_map;

	// get next word
	const char *delimiters = " \t\n\r,.?!\"\'";
    char *word = strtok(line, delimiters);

	bool match;
    while (word != NULL) {

		// get word pointer for backward reading
		char *pword = word + strlen(word) - 1;

		// convert to lowercase
		tolower_eo(word);

		// check whole word
		// 0: whole words
		match = check_full(word, defs, 0, base_map);

		// 0  - 2: prefixes
		// 3  - 5: roots
		// 6  - 10: postfixes
		// 11 - 13: endings
		if (!match) {
			// check ending and root
			pword = check_end(pword, defs, 13);
			match = check_full(word, defs, 3, root_map);

			// check prefixes, postfixes, roots
			if (!match) {
				word = check_f(word, defs, 0, pre_map);
				// pword = check_b(pword, word, defs, 10, post_map);
				pword = check_b(pword, word, defs, 5, root_map);
			}

		}

		read_defs(defs);
		clear_defs(defs);

		// get next word
        word = strtok(NULL, delimiters);
    }
}

int main() {
	// open and read file into buffer
    FILE *fp = fopen("ex.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

	// init maps and unite them
	Map *base_map = init_base_map();
	Map *root_map = init_map_with(roots);
	Map *pre_map  = init_map_with(prefixes);
	Map *post_map = init_map_with(postfixes);
	Maps *maps = malloc(sizeof(*maps));
	*maps = (Maps){base_map, root_map, pre_map, post_map};

	// init definitions
	char (*defs)[DEF_LEN] = malloc(DEF_NUM * sizeof(*defs));

	// check each word against maps
	char line[4096];
	while ((fgets(line, sizeof(line), fp)) != NULL) {
		analyze(line, defs, maps);
	}
	fflush(stdout);

	// gracefully exit
    fclose(fp);
    return 0;
}
