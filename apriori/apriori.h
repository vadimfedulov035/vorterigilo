#ifndef APRIORI_H
#define APRIORI_H

#define PRONOUNS_NUM ((9 * 8) + (5 * 4) + 8 + 4)
#define NUMERALS_NUM (9 * 13)
#define CORRELATIVES_NUM (6 * 26)
#define FUNCTION_WORDS_NUM 101
#define ABBREVIATIONS_NUM 10

#define APRIORI_NUM ( \
    PRONOUNS_NUM + \
    NUMERALS_NUM + \
    CORRELATIVES_NUM + \
	FUNCTION_WORDS_LEN + \
    ABBREVIATIONS_NUM \
)

#define WORD_LEN 128

extern char pronouns[PRONOUNS_NUM*2][WORD_LEN];
extern char numerals[NUMERALS_NUM*2][WORD_LEN];
extern char correlatives[CORRELATIVES_NUM*2][WORD_LEN];
extern char function_words[FUNCTION_WORDS_NUM*2][WORD_LEN];
extern char abbreviations[ABBREVIATIONS_NUM*2][WORD_LEN];

struct hashmap* init_apriori_map();

struct word_desc {
    char *word;
    char *desc;
};

// PARTS OF SPEECH
// many categories
#define NOUN   "noun"
#define PRO    "pronoun"
#define DET    "determiner"
#define ADV    "adverb"
#define PREP   "preposition"
#define NUM    "numeral"

// no categories
#define DART   " (definite article)"
#define PART   " (particle)"
#define INTJ   " (interjection)"
#define CONJ   " (conjunction)"

// TYPES
// noun types
#define ABBR   " abbreviated)"

// pronoun types
#define PERS   " (personal"
#define MULT   " (multal"
#define PAUC   " (paucal"
#define RECI   " (reciprocal"

#define SUB    " subject "
#define OBJ    " object "
#define POS    " possesive "
#define REF    " reflexive "

// determiner types
#define SEL    "selective "
#define DES    "descriptive "
#define FORM   " formal"

// numeral types
#define CARD   " (cardinal "
#define ORD    " (ordinal "
#define SUBZ   " (substantivized "

// adverb types
#define PLACE  " of place)"
#define MOTION " of motion)"
#define TIME   " of time)"
#define MANNER " of manner)"
#define REASON " of reason)"
#define AMOUNT " of amount)"
#define DEGREE " of degree)"

// correlatives types (+ pronoun type)
#define INTER " (interrogative "
#define RELAT " (relative "
#define DEMON " (demonstrative "
#define INDEF " (indefinite "
#define UNIVE " (universal "
#define NEGAT " (negative "

// CATEGORIES
// category of person (first)
#define FIR   ", first person"
#define SEC   ", second person"
#define THI   ", third person"

// category of number (first/second)
#define SING  ", singular number"
#define PLUR  ", plural number"
#define UN    ", undefined number"

// category of gender (middle)
#define M     ", male gender"
#define F     ", female gender"
#define N     ", neuter gender"
#define EP    ", epicene gender"

// category of case (last)
#define NOM   ", nominative case)"
#define ACC   ", accusative case)"
#define RGEN  ", rudimentary form of genitive case)"
#define UC    ", undefined case)"

// DEFINITIONS
#define THISELF "himself/herself/itself"

// RECIPROCAL PRONOUNS
// "each other" RECIPROCAL OBJ PRO,
//
// "both"

#endif
