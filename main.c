#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "map/map.h"

#include "vocab/vocab.h"
#include "morph/morph.h"


struct maps_struct {
    struct map *pre_map;
    struct map *core_map;
    struct map *root_map;
    struct map *post_map;
};


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

void print_res(char *dst) {
	char *res = dst;
	const char *pattern = "[EXC] (";
	const int pattern_len = 7;

	char *exc = strstr(res, pattern);
	if (exc != NULL) {
		res = exc + pattern_len;
		res[strlen(res) - 1] = '\0';
	}
	printf("%s, ", res);
}


void print_all(char (*out)[OUT_LEN], int *l_idx, int *r_idx) {
	bool is_read = false;
	char *res;

	// print (->)
	for (int i = 0; i < *l_idx ; i++) {
		is_read = true;
		print_res(out[i]);
		strcpy(out[i], "");
	}

	// print (<-)
	for (int i = ++(*r_idx); i < OUT_NUM; i++) {
		is_read = true;
		print_res(out[i]);
		strcpy(out[i], "");
	}

	if (is_read) {
		printf("\b\b \n");
	}
}


void morphemize(char *line, char (*out)[OUT_LEN], struct maps_struct *maps) {

	struct map *pre_map  = maps->pre_map;
	struct map *core_map = maps->core_map;
	struct map *root_map = maps->root_map;
	struct map *post_map = maps->post_map;

	const char *ds = " \t\n\r,.?!\"";
	char *lword, *rword;
	int l_idx, r_idx;

	bool match = false;
    for (lword = strtok(line, ds); lword != NULL; lword = strtok(NULL, ds)) {
		rword = lword + strlen(lword) - 1;

		if (match) {
			match = false;
			print_all(out, &l_idx, &r_idx);
		}

		l_idx = 0;
		r_idx = OUT_NUM - 1;

		// core check
		tolower_eo(lword);
		match = check_full(lword, out, &l_idx, core_map);
		if (match) {
			continue;
		}

		if (strlen(lword) < 3) {
			continue;
		}

		// root check without -j, -n
		rword = check_end_jn(rword, out, &r_idx);
		match = check_full(lword, out, &l_idx, root_map);
		if (match) {
			continue;
		}

		// root check without -o, -a, -e
		rword = check_end_oae(rword, out, &r_idx);
		match = check_full(lword, out, &l_idx, root_map);
		if (match) {
			continue;
		}

		char *lword_orig = lword;
		char *rword_orig = rword;

		// check forth prefixes, roots, postfixes
		lword = check_forth(lword, out, &l_idx, pre_map);
		lword = check_forth(lword, out, &l_idx, root_map);

		//printf("AFTER FORTH: %s\n", lword);

		// check back prefixes, roots, postfixes (reversed)
		//rword = check_back(lword, out, &r_idx, post_map);
		//rword = check_back(lword, out, &r_idx, root_map);

		if (lword != lword_orig || rword != rword_orig) {
			match = true;
		} else {
			printf("Unknown word: %s\n", lword);
		}
    }
}


int main() {
    FILE *fp = fopen("text.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

	struct map *pre_map  = init_map_with(prefixes);
	struct map *core_map = init_map_with(cores);
	struct map *root_map = init_map_with(roots);
	struct map *post_map = init_map_with(postfixes);

	struct maps_struct *maps = malloc(sizeof(*maps));
	*maps = (struct maps_struct){pre_map, core_map, root_map, post_map};

	char (*out)[OUT_LEN] = malloc(OUT_NUM * sizeof(*out));
	for (int i = 0; i < OUT_NUM; i++) {
		strcpy(out[i], "");
	}

	char line[4096];
	while ((fgets(line, sizeof(line), fp)) != NULL) {
		morphemize(line, out, maps);
	}
	fflush(stdout);

	// gracefully exit
    fclose(fp);
    return 0;
}
