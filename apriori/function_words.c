#include "apriori.h"


char function_words[FUNCTION_WORDS_NUM*2][WORD_LEN] = {
	// POSITION DEPENDENT WORDS
	// (flag if in the clause beginning)
	"nu!",      "well / I mean"       INTJ,
    "do!",      "so"                  CONJ,
    "jes!",     "yes"                 INTJ,
	"ne!",      "ne"                  INTJ,
	// (no flag if not in the clause beginning)
	"nu",       "well / I mean"       CONJ,
    "do",       "so"             " (" ADV,
    "jes",      "yes"            " (" ADV,
	"ne",       "ne"                  PART,
	
	
	// NUMERAL DEPENDENT WORDS
	// (flag if numeral after)
    "dum!",     "for (past)"     " (" PREP TIME,
    "por!",     "for (future)"   " (" PREP TIME,
	"ĉirkaŭ!",  "around"         " (" ADV  AMOUNT,
	// (no flag if no numeral after)
    "dum",      "while"               CONJ,
    "por",      "for"            " (" PREP MANNER,
	"ĉirkaŭ",   "around"         " (" ADV  PLACE,  


	// INTERJECTIONS
    "ho",       "oh"                  INTJ,
    "ve",       "geez"                INTJ,


    // CONJUNCTIONS
	"ĉu",       "whether"             CONJ,
    "se",       "if"                  CONJ,
    "kaj",      "and"                 CONJ,
    "aŭ",       "or"                  CONJ,
    "nek",      "neither/nor"         CONJ,
	"kaŭ",      "and/or"              CONJ,
    "sed",      "but"                 CONJ,
    "tamen",    "however"             CONJ,
    "kvankam",  "although"            CONJ,
    "ke",       "that"                CONJ,
    "ĉar",      "because"             CONJ,
    "ol",       "than"                CONJ,
    "kvazaŭ",   "as if"               CONJ, 


    // PREPOSITIONS AND ADVERBS
	// SIMPLE
    "de",        "of (relation)"  " (" PREP ")",
    "da",        "of (quantity)"  " (" PREP ")",
    "je",        "<ad hoc>"       " (" PREP ")",
	"eĉ",        "even"           " (" ADV  ")",
	"nur",       "only"           " (" ADV  ")",
	"ankaŭ",     "also"           " (" ADV  ")",
	"almenaŭ",   "at least"       " (" ADV  ")",
	"plus",      "plus"           " (" PREP ")",
	"minus",     "minus"          " (" PREP ")",
	

	// PLACE/MOTION
	// (flag if no accusative case after)
    "en!",       "in"             " (" PREP PLACE,
    "sur!",      "on"             " (" PREP PLACE,
    "sub!",      "under"          " (" PREP PLACE,
    "super!",    "over"           " (" PREP PLACE,
    "ekster!",   "outside"        " (" PREP PLACE,
    "antaŭ!",    "before"         " (" PREP PLACE,
    "malantaŭ!", "behind"         " (" PREP PLACE,
	// (no flag if accusative case after)
    "en",        "in"             " (" PREP MOTION,
    "sur",       "on"             " (" PREP MOTION,
    "sub",       "under"          " (" PREP MOTION,
    "super",     "over"           " (" PREP MOTION,
    "ekster",    "outside"        " (" PREP MOTION,
    "antaŭ",     "before"         " (" PREP MOTION,
    "malantaŭ",  "behind"         " (" PREP MOTION,


	// PLACE
    "ĉe",        "at"             " (" PREP PLACE,
	"apud",      "next to"        " (" PREP PLACE,
	"inter",     "between"        " (" PREP PLACE,
	"jen",       "here"           " (" ADV  PLACE,


	// MOTION
    "al",        "to"             " (" PREP MOTION,
    "el",        "out"            " (" PREP MOTION,
	"tra",       "across"         " (" PREP MOTION,
	"trans",     "through"        " (" PREP MOTION,
	"preter",    "past"           " (" PREP MOTION,
	"for",       "away"           " (" ADV  MOTION,
	"plu",       "beyond/further" " (" ADV  MOTION,


	// TIME
	"ĝis",       "since"          " (" PREP TIME,
	"ekde",      "until"          " (" PREP TIME,
	"post",      "after"          " (" PREP TIME,
	"nun",       "now"            " (" ADV  TIME,
	"ĵus",       "at once"        " (" ADV  TIME,
	"tuj",       "just"           " (" ADV  TIME,
	"ankoraŭ",   "still/yet"      " (" ADV  TIME,
	"jam",       "already"        " (" ADV  TIME,
	"baldaŭ",    "soon"           " (" ADV  TIME,
	"hieraŭ",    "yesterday"      " (" ADV  TIME,
	"hodiaŭ",    "today"          " (" ADV  TIME,
	"morgaŭ",    "tomorrow"       " (" ADV  TIME,


	// MANNER
    "pro",       "because of"     " (" PREP MANNER,
    "per",       "via"            " (" PREP MANNER,
    "pri",       "about"          " (" PREP MANNER,
	"po",        "per"            " (" PREP MANNER,
    "kun",       "with"           " (" PREP MANNER,
	"sen",       "without"        " (" PREP MANNER,
	"krom",      "besides"        " (" PREP MANNER,
    "laŭ",       "according to"   " (" PREP MANNER,
    "mallaŭ",    "against the"    " (" PREP MANNER,
    "kontraŭ",   "against the"    " (" PREP MANNER,
    "graŭ",      "as a result of" " (" PREP MANNER,
    "malgraŭ",   "despite"        " (" PREP MANNER,
    "spite",     "despite"        " (" PREP MANNER,
	"ĉiuokaze",  "anyway"         " (" ADV  MANNER,


	// DEGREE
	"ju",        "the"            " (" ADV  DEGREE,
	"des",       "the"            " (" ADV  DEGREE,
	"pli",       "more"           " (" ADV  DEGREE,
	"plej",      "most"           " (" ADV  DEGREE,
	"preskaŭ",   "almost"         " (" ADV  DEGREE,
	"apenaŭ",    "barely"         " (" ADV  DEGREE,
	"ja",        "indeed"         " (" ADV  DEGREE,
	"tre",       "very"           " (" ADV  DEGREE,
	"tro",       "too"            " (" ADV  DEGREE,


	// SPECIAL DETERMINERS
	"la",       "the"                  DART,
	"ĉi",       "one"                  RELAT SEL DET ")",
	"ajn",      "any"                  INDEF DES DET UN   UC,
};
