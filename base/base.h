#ifndef BASE_H
#define BASE_H

#ifndef STDDEF_H
#define NULL ((void *)0)
#endif

extern char *pronouns[];
extern char *numerals[];
extern char *correlatives[];
extern char *functors[];
extern char *abbreviations[];

// PARTS OF SPEECH
// many categories
#define NOUN   "noun"
#define PRO    "pronoun"
#define DET    "determiner"
#define ADJ    "adjective"
#define ADV    "adverb"
#define VERB   "verb"
#define PREP   "preposition"
#define NUM    "numeral"

// no categories
#define DART   "definite article"
#define PART   "particle"
#define INTJ   "interjection"
#define CONJ   "conjunction"

// TYPES
// noun types
#define ABBR   " abbreviated"

// pronoun types
#define PERS   "personal"
#define MULT   "multal"
#define PAUC   "paucal"
#define RECI   "reciprocal"

#define SUB    " subject "
#define OBJ    " object "
#define POS    " possesive "
#define REF    " reflexive "

// determiner types
#define SEL    "selective "
#define DES    "descriptive "
#define FORM   " formal"

// numeral types
#define CARD   "cardinal "
#define ORD    "ordinal "
#define SUBZ   "substantivized "

// adverb types
#define PLACE  " of place"
#define MOTION " of motion"
#define TIME   " of time"
#define MANNER " of manner"
#define REASON " of reason"
#define AMOUNT " of amount"
#define DEGREE " of degree"

// correlatives types (+ pronoun type)
#define INTER "interrogative "
#define RELAT "relative "
#define DEMON "demonstrative "
#define INDEF "indefinite "
#define UNIVE "universal "
#define NEGAT "negative "

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
#define NOM   ", nominative case"
#define ACC   ", accusative case"
#define RGEN  ", rudimentary genitive case"
#define UC    ", undefined case"

// DEFINITIONS
#define THISELF "himself/herself/itself"

// RECIPROCAL PRONOUNS
// "each other" RECIPROCAL OBJ PRO,
//
// "both"

#endif
