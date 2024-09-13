#ifndef ENDINGS_H
#define ENDINGS_H

#define BASE_ENDINGS_NUM 5
#define CORRELATIVE_ENDINGS_NUM 6 
#define VERBAL_ENDINGS_NUM 14

// base endings partially overlap with correlative endings
const char base_endings[BASE_ENDINGS_NUM] = {
    'n',    // accusative case
    'j',    // plural form
    'o',    // noun (or thing)
    'a',    // adjective (or quality)
    'e',    // adverb (or place)
};

// correlative endings not overlapping with base endings
const char correlative_endings[CORRELATIVE_ENDINGS_NUM][2] = {
    "u",    // individual
    "al",   // reason
    "el",   // manner
    "am",   // time
    "om",   // amount
    "es",   // association
};

// verbal endings with respect to aspectism
const char verbal_endings[VERBAL_ENDINGS_NUM][4] = {
    "as",   // present tense verb
    "is",   // past tense verb
    "os",   // future tense verb
    "us",   // conditional verb
    "u",    // volitive verb
    "i"     // infinitive verb
    "ant",  // present active participle
    "it",   // past passive participle
    "int",  // past active participle
    "at",   // present passive participle
    "ont",  // future active participle
    "ot",   // future passive participle
    "unt",  // conditional active participle
    "ut",   // conditional passive participle
};

#endif
#ifndef PREFIXES_H
#define PREFIXES_H

#define PREFIXES_NUM 10

const char prefixes[PREFIXES_NUM][4] = {
    "mal",  // antonym
    "ek",   // beginning
    "re",   // over again
    "fi",   // shameful
    "ge",   // both sexes
    "bo",   // in-law
    "pra",  // great- (grand-)
    "dis",  // separation, scattering
    "mis",  // incorrectly
    "eks",  // former, ex-
};

#endif
#ifndef ROOTS_H
#define ROOTS

#define CORRELATIVE_ROOTS_NUM 5

const char correlative_roots[CORRELATIVE_ROOTS_NUM][5] = {
    "ki",   // question (what)
    "ti",   // indication (this/that)
    "i",    // indefinite (some)
    "ĉi",   // universal (each/every)
    "neni", // no
};

#endif
#ifndef SUFFIXES_H
#define SUFFIXES_H

#define SUFFIXES_NUM 30

// suffixes ordered according occurence and frequency
const char suffixes[SUFFIXES_NUM][5] = {
    "aĉ",   // pejorative
    "ad",   // continuous
    "eg",   // augmentative
    "et",   // diminutive
    "ar",   // collection
    "er",   // the smallest part
    "ig",   // causative
    "iĝ",   // anticausative
    "aĵ",   // concrete manifestation
    "ec",   // abstract quality
    "em",   // having tendency
    "ejo",  // place
    "in",   // female
    "ist",  // professional
    "an",   // member
    "ul",   // person
    "il",   // instrument
    "uj",   // container (or country)
    "i",    // country
    "estr", // boss
    "ind",  // worthy of
    "end",  // mandatory
    "um",   // undefined (ad hoc)
    "obl",  // multiple
    "on",   // fraction
    "nj",   // female truncated
    "ĉj",   // male truncated
    "id",   // offspring / kid
    "iĉ",   // male (reform)
    "ing",  // holder
};

#endif
