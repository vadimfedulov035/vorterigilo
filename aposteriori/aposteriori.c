#ifndef ENDINGS_H
#define ENDINGS_H

// verbal endings
char verbal_endings[VERBAL_ENDINGS_NUM][WORD_LEN] = {
    "is",  "past tense verb", 
	"as",  "present tense verb",
	"os",  "future tense verb",
	"us",  "conditional verb",
	"u",   "volitive verb",
	"int", "past active participle",
	"ant", "present active participle",
	"ont", "future active participle",
	"it",  "past passive participle",
	"at",  "present passive participle",
	"ot",  "future passive participle",
};

// suffixes ordered according oppositions
const char suffixes[SUFFIXES_NUM*2][WORD_LEN] = {
	// affection category
    "aĉ",   "pejorative",        // derogatory affection
    "eg",   "augmentative",      // accentuated affection
	"et",   "diminutive",        // lenient affection
	// modality category
    "ind",  "worthy of",         // weak modality
	"end",  "mandatory",         // strong modality
	// transitivity category
    "ig",   "causative",         // intransitive 
	"iĝ",   "anticausative",     // transitive
	// discrete partiality category
    "ar",   "collection",        // complementary discrete partiality
	"er",   "particle",          // fragmentary discrete partiality
	// continuous partiality category
    "obl",  "multiple",          // complementary continuous partiality
	"on",   "fraction",          // fragemntary continous partiality
	// conceptuality category
    "aĵ",   "manifestation",     // concrete conceptuality
	"ec",   "quality",           // abstract conceptuality
	// locality category
	"i",    "country",           // state locality
	"uj",   "container/country", // relation locality
    "ej",   "place",             // activity locality
	// gender category
	"in",   "female",            // female gender
	"iĉ",   "male",              // male gender
	// parentiality category
	"id",   "kid",               // direct parentiality (literate style)
	// identity category 
	"an",   "member",            // group identity
	"ul",   "person",            // personal identity
	// class category
	"ist",  "professional",      // proletariat class
    "estr", "boss",              // bourgeoisie class
	// instrumentality category
	"il",   "instrument",        // active instrumentality
	"ing",  "holder",            // passive instrumentality
	// habituality category
	"em",   "prone to",          // general habituality
	"ad",   "continuous",        // factual habituality
	// gender affection category
    "nj",   "female diminutive", // female gender
	"ĉj",   "male diminuitive",  // male gender
	// no category
    "um",   "<ad hoc>",
};

const char prefixes[PREFIXES_NUM][8] = {
    "mal", "ek", "re", "fi",
	"ge", "bo", "pra",
	"dis", "mis", "eks",
};

char prefixes_desc[PREFIXES_NUM][8] = {
	"un-/in-", "beginning", "re-", "shameful",
	"both sexes", "in-law", "great-/grand-",
	"separation / scattering", "incorrectly", "ex-",
};
