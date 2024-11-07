#include <stdio.h>
#include <string.h>

#include "../map/map.h"

#include "../vocab/vocab.h"
#include "morph.h"


bool check_full(char *word, char (*out)[OUT_LEN], int *i, struct map *map) {
    const VocabUnit *res;
	res = map_get(map, &(VocabUnit){ .word=word});
	bool match = (res != 0);
	if (match) {
		sprintf(out[(*i)++],
				"%s [%s] (%s)",
				res->word, res->transl, res->def);
	}

	return match;
}


char *check_end_jn(char *rword, char (*out)[OUT_LEN], int *i) {

	/* indicate case (-/-n) and number (-/-j) categories *
	 * for nouns (-o) and adjectives (-a), adverbs (-e)  *
	 * can only have (-n) case indicating motion         */

	char *rword_orig = rword;

	bool acc = false;
	bool plur = false;
	for (bool done = false; !done; rword--) {
		switch (*rword) {
			case 'n':
				acc = true;
				sprintf(out[(*i)--], ACC_CASE);
				break;
			case 'j':
				plur = true;
				sprintf(out[(*i)--], PLUR_NUM);
				break;
			case 'o':
			case 'a':
				if (!acc) {
					sprintf(out[(*i)--], NOM_CASE);
				}
				if (!plur) {
					sprintf(out[(*i)--], SING_NUM);
				}
			default:
				done = true;
				rword[1] = '\0';
				break;
		}
	}

	return ++rword;
}


char *check_end_oae(char *rword, char (*out)[OUT_LEN], int *i) {

	/* indicate word class                           *
	 * for nouns (-o), adjectives (-a), adverbs (-e) *
	 * and abbreviations (-')                        */

	char *rword_orig = rword;

	char *dst = out[(*i)--];
	switch (*rword--) {
		case 'o':
			sprintf(dst, NOUN_WC); 
			break;
		case 'a':
			sprintf(dst, ADJ_WC); 
			break;
		case 'e':
			sprintf(dst, ADV_WC); 
			break;
		case '\'':
			sprintf(dst, ABBR); 
			break;
		default:
			rword++;
			i++;
			break;
	}
	rword[1] = '\0';

	return rword;
}


bool check_verb_end_2(char *rword, char *dst) {
	bool match = true;

	// roll through pre-last character
	switch (*rword) {
		case 'i':
			sprintf(dst, PAST_VERB); 
			break;
		case 'a':
			sprintf(dst, PRES_VERB); 
			break;
		case 'o':
			sprintf(dst, FUTUR_VERB); 
			break;
		case 'u':
			sprintf(dst, COND_VERB); 
			break;
		default:
			match = false;
			break;
	}

	return match;
}


bool check_verb_end_1(char *rword, char *dst) {
	bool match = true;

	// roll through last character
	switch (*rword) {
		case 'i':
			sprintf(dst, INF_VERB); 
			break;
		case 'u':
			sprintf(dst, VOL_VERB); 
			break;
		case 's':
			match = check_verb_end_2(--rword, dst);
			break;
		default:
			match = false;
			break;
	}

	return match;
}


char *check_verb_end(char *rword, char (*out)[OUT_LEN], int *i) {

	// check ending and terminate matched part
	char *dst = out[(*i)--];
	bool match = check_verb_end_1(rword, dst);
	if (match) {
		*rword = '\0';
		rword--;
	// increment after extra decrement
	} else {
		i++;
	}

	return rword;
}


char *check_forth(char *word, char (*out)[OUT_LEN], int *i, struct map *map) {

	// check forth ungreedy (buffer smaller -> partial strcpy)
    const VocabUnit *res;
    for (size_t n = strlen(word); n > 0; n--) {

		// set buffer with n characters
		char buf[n + 1];
		strcpy(buf, word);
		buf[n] = '\0';

        res = map_get(map, &(VocabUnit){ .word=buf });
        if (res != 0) {
            sprintf(out[(*i)++], "%s [%s] (%s)",
					res->word, res->transl, res->def);
			// reset
			word = word + n;
			n = strlen(word);
			// make up extra dec
			n++;
        }
    }

	return word;
}


char *check_back(char *word, char (*out)[OUT_LEN], int *i, struct map *map) {

	// memorize word pointer
	char *lword = word;

    // check back ungreedy (buffer smaller -> partial strcpy) 
    const struct VocabUnit *res;
	for (size_t n = strlen(word); n > 0; n--, word++) {

		// set buffer with n characters
		char buf[n + 1];
		strcpy(buf, word);
		buf[n] = '\0';

        res = map_get(map, &(VocabUnit){ .word=buf });
        if (res != 0) {
            sprintf(out[(*i)--], "%s [%s] (%s)",
					res->word, res->transl, res->def);
            *(word) = '\0';
			// reset
			word = lword;
			n = strlen(word);
			// make up extra dec
			word--;
			n++;
        }
    }

	return word;
}
