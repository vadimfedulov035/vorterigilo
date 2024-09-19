#include "morph.h"


char *suffixes[] = {
	// affection category
    "aĉ",   "pejorative",            "derogatory affection",
    "eg",   "augmentative",          "accentuated affection",
	"et",   "diminutive",            "lenient affection",

	// modality category
    "ind",  "worthy of",             "weak modality",
	"end",  "mandatory",             "strong modality",

	// transitivity category
    "ig",   "causative",             "transitive by causation",
	"iĝ",   "anticausative",         "intransitive by anticausation",

	// discrete partiality category
    "ar",   "collection",            "complementary discrete partiality",
	"er",   "particle",              "fragmentary discrete partiality",

	// continuous partiality category
    "obl",  "multiple",              "complementary continuous partiality",
	"on",   "fraction",              "fragemntary continous partiality",

	// conceptuality category
    "aĵ",   "manifestation",         "concrete conceptuality",
	"ec",   "quality",               "abstract conceptuality",

	// locality category
	"i",    "country",               "state locality",
	"uj",   "container/country",     "relation locality",
    "ej",   "place",                 "activity locality",

	// gender category
	"in",   "female",                "female gender",
	"iĉ",   "male",                  "male gender",

	// parentiality category
	"id",   "kid",                   "direct parentiality",

	// identity category 
	"an",   "member",                "group identity",
	"ul",   "person",                "personal identity",

	// class category
	"ist",  "professional",          "working class",
    "estr", "boss",                  "ruling class",

	// instrumentality category
	"il",   "instrument",            "active instrumentality",
	"ing",  "holder",                "passive instrumentality",

	// habituality category
	"em",   "prone to",              "general habituality",
	"ad",   "continuous",            "factual habituality",

	// gender affection category
    "nj",   "female diminutive",     "female gender",
	"ĉj",   "male diminuitive",      "male gender",

	// no category
    "um",   "<ad hoc>",              "undefined category",

	NULL,
};
