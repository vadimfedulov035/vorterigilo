#include <stdio.h>
#include <string.h>

#include "../hashmap/hashmap.h"

#include "../vocab/vocab.h"
#include "../base/base.h"
#include "morph.h"


bool check_full(char *word, char (*defs)[DEF_LEN], int i, Map *map) {
	bool match = false;

    const VocabUnit *res;
	res = hashmap_get(map, &(VocabUnit){ .word=word});
	match = (res != 0);
	if (match) {
		sprintf(defs[i++], "%s - %s (%s)", res->word, res->transl, res->def);
	}

	return match;
}


char *check_category(char *pword, char (*defs)[DEF_LEN], int *i) {

	/* indicate case (0/-n) and number (0/-j)
	 * for nouns (-o) and adjectives (-a) */

	// category flags
	bool acc = false;
	bool plur = false;
	// loop flag
	bool done = false;
	while (!done) {
		switch(*pword) {
			case 'n':
				acc = true;
				sprintf(defs[(*i)--], "-%c (accusative case)", *pword); 
				pword--;
				break;
			case 'j':
				plur = true;
				sprintf(defs[(*i)--], "-%c (plural number)", *pword); 
				pword--;
				break;
			case 'o':
			case 'a':
				if (!acc) {
					sprintf(defs[(*i)--], "- (nominative case)"); 
				}
				if (!plur) {
					sprintf(defs[(*i)--], "- (singular number)"); 
				}
			// fall through without decrement
			// for world class check later
			default:
				done = true;
				break;
		}
	}
	
	return pword;
}


int check_wc_base(char ch) {
	// error value by default
	int wc = -1;
	// base endings (last ending demands another check)
	const char endings[] = {'o', 'a', 'e', 'i', 'u', 's'};
	for (int i = 0; i < 6; i++) {
		if (ch == endings[i]) {
			wc = i;
		}
	}
	return wc;
}


int check_wc_ext(char ch) {
	// error value by default
	int wc = -1;
	// extended ending
	const char endings[] = {'u', 'i', 'a', 'o'};
	for (int i = 0; i < 6; i++) {
		if (ch == endings[i]) {
			wc = 5 + i;
		}
	}
	return wc;
}


char *check_word_class(char *pword, char (*defs)[DEF_LEN], int *i) {

	/* indicate word class based on 1 or 2 character endings
	 * word class 5 has subclasses and is redefined later    */

	// initialize word classes
	char *wc_arr[] = {
		NOUN, ADJ, ADV, INF VERB, VOL VERB,           // base     (1 char)
		COND VERB, PAST VERB, PRES VERB, FUTUR VERB,  // extended (2 char)
	};

	// check for base endings
	int wc = check_wc_base(*pword);
	// check for extended endings
	if (wc == 5) {
		wc = check_wc_ext(*(--pword));
	// or terminate after one character
	} else {
		pword[1] = '\0';
	}

	// print on match (no pword decrement)
	if (wc != -1) {
		sprintf(defs[(*i)--], "-%s (%s)", pword, wc_arr[wc]); 
		*pword = '\0';
	}

	return pword;
}


char *check_end(char *pword, char (*defs)[DEF_LEN], int i) {
	pword = check_category(pword, defs, &i);
	pword = check_word_class(pword, defs, &i);
	return pword;
}


char *check_f(char *word, char (*defs)[DEF_LEN], int i, Map *map) {
	bool match = false;

    // word is read forwards
	// descriptions are written forwards
	// word end pointer stays valid
    const VocabUnit *res;
	char word_tmp[128];
	char *word_end = word + strlen(word);
    for (int j = 0; word + j < word_end; j++) {
		// copy word
		strcpy(word_tmp, word);
		// terminate copied word after i characters
		word_tmp[j] = '\0';
		// check terminated copy
        res = hashmap_get(map, &(VocabUnit){ .word=word_tmp });
		match = (res != 0);
        if (match) {
            sprintf(defs[i++], "%s - %s (%s)",
					res->word, res->transl, res->def);
			// shift until not matched part
			word = word + j;
			// reset index 
			j = 0;
        }
    }

	return word;
}


char *check_b(char *pword, char *word, char (*defs)[DEF_LEN], int i, Map *map) {
	bool match = false;

    // word is read backwards
	// descriptions are written forwards
	// word pointer serves as border
    const struct VocabUnit *res;
    while (--pword >= word) {
        res = hashmap_get(map, &(VocabUnit){ .word=pword });
		match = (res != 0);
        if (match) {
			match = true;
            sprintf(defs[i--], "%s - %s (%s)",
					res->word, res->transl, res->def);
            *pword = '\0';
        }
    }

	return pword;
}
