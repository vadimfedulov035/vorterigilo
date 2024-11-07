#ifndef MORPH_H
#define MORPH_H

#ifndef STDDEF_H
#define NULL ((void *)0)
#endif

#define OUT_NUM 20
#define OUT_LEN 500

extern char *postfixes[];
extern char *cores[];
extern char *roots[];
extern char *prefixes[];

#include "../map/map.h"
#include "../vocab/vocab.h"

// check full word
bool check_full(char *word, char (*defs)[OUT_LEN], int *i, struct map *map);

// check ending
char *check_end_jn(char *rword, char (*out)[OUT_LEN], int *i);
char *check_end_oae(char *rword, char (*out)[OUT_LEN], int *i);

// check partial word
char *check_forth(char *word, char (*defs)[OUT_LEN], int *i, struct map *map);
char *check_back(char *word, char (*defs)[OUT_LEN], int *i, struct map *map);


// CATEGORY OF CASE (definition)
#define ACC_CASE "-n (accusative case)"
#define NOM_CASE "- (nominative case)"

// CATEGORY OF NUMBER (definition)
#define PLUR_NUM "-j (plural number)"
#define SING_NUM "- (singular number)"

// WORD CLASSES
#define NOUN_WC    "-o (noun)"
#define ADJ_WC     "-a (adjective)"
#define ADV_WC     "-e (adverb)"
#define TRUNC_WC   "-' (truncated)"

// SERVE WORD CLASSES
#define ANSW    "answer word"
#define ADV     "adverb"
#define INTJ    "interjection"
#define PREP    "preposition"
#define CONJ    "conjunction"
#define ABBR    "abbrevition"

// SERVE WORD TYPES
#define TIME    " of time"
#define MANNER  " of manner"
#define PLACE   " of place"
#define MOTION  " of motion"
#define DEGREE  " of degree"

// PRONOUN TYPES
#define PER     "personal "
#define IND     "indefinite "
#define PRO     "pronoun"
#define POS_DET  "-a (possessive determiner)"

// NUMERAL
#define NUM     "cardinal numeral"
#define ORD_NUM  "-a (ordinal numeral)"

// CORRELATIVE TYPES (pronouns can take -es)
// PART I
#define INTER_PRO   "Ki- [Wh-] (correlative), "
#define RELAT_PRO   "ki- [wh-] (correlative), "
#define DEMON_PRO   "ti- [th-] (correlative), "
#define INDEF_PRO   "i- [some-] (correlative), "
#define UNIVE_PRO   "ĉi- [every-] (correlative), "
#define NEGAT_PRO   "neni- [no-] (correlative), "

// PART II
#define COR_PRO     "-o (pronoun)"
#define SEL_DET     "-u (selective determiner)"
#define DES_DET     "-a (descriptive determiner)"
#define POS_PRO     "-es (possessive pronoun)"
#define TIME_ADV    "-am (time adverb)"
#define MANNER_ADV  "-el (manner adverb)"
#define REASON_ADV  "-al (reason adverb)"
#define AMOUNT_ADV  "-om (amount adverb)"
#define PLACE_ADV   "-e (place adverb)"

// VERB
#define INF_VERB     "infinitive "
#define VOL_VERB     "volitive "
#define PAST_VERB    "paste tense "
#define PRES_VERB    "present tense "
#define FUTUR_VERB   "future tense "
#define COND_VERB    "conditional "

// CATEGORY OF PERSON (first)
#define FIR     ", first person"
#define SEC     ", second person"
#define THI     ", third person"

// CATEGORY OF NUMBER (first/second)
#define SING    ", singular number"
#define PLUR    ", plural number"
#define BOTH    ", undefined number"

// CATEGORY OF GENDER (middle)
#define M       ", male gender"
#define F       ", female gender"
#define N       ", neuter gender"
#define EP      ", epicene gender"

#endif
