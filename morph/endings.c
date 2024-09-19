#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "morph.h"
#include "../base/base.h"

#define PAST "paste tense"
#define PRES "present tense"
#define FUTUR "future tense"

char *verb_endings[] = {
	// verbs
    "is",  "V + -ed",                "past tense verb", 
	"as",  "V",                      "present tense verb",
	"os",  "will + V",               "future tense verb",
	"us",  "would + V",              "conditional verb",
	"u",   "let's + V",              "volitive verb",

	// active participles
	"int", "have + V + -ed",         "past active participle",
	"ant", "V + -ing",               "present active participle",
	"ont", "will have + V + -ed",    "future active participle",

	// passive participles
	"it",  "is + V + -ed",           "past passive participle",
	"at",  "is being + V + -ed",     "present passive participle",
	"ot",  "will be + V + -ed",      "future passive participle",

	NULL,
};

void check_endings(struct Pointers *ptrs) {
	char *word = ptrs->word;
	int i = ptrs->i;
	int j = ptrs->j;

	// case check
	char desc[128];
	bool acc = false;
	bool plur = false;
	bool done = false;
	while (!done) {
		switch(word[i]) {
			case 'n':
				acc = true;
				strcpy(desc, "accusative case");
				sprintf(ptrs->descs[j++], "%c (%s)", word[i--], desc); 
				break;
			case 'j':
				plur = true;
				strcpy(desc, "plural number");
				sprintf(ptrs->descs[j++], "%c (%s)", word[i--], desc); 
				break;
			case 'o':
			case 'a':
				if (!acc) {
					strcpy(desc, "nominative case");
					sprintf(ptrs->descs[j++], "- (%s)", desc); 
				}
				if (!plur) {
					strcpy(desc, "singular number");
					sprintf(ptrs->descs[j++], "- (%s)", desc); 
				}
			// fall through
			default:
				done = true;
				break;
		}
	}

	// part of speech check
	bool match = true;
	bool verb_exc = false;
	switch(word[i]) {
		case 'o':
			strcpy(desc, NOUN);
			break;
		case 'a':
			strcpy(desc, ADJ);
			break;
		case 'e':
			strcpy(desc, ADV);
			break;
		case 'i':
		case 'u':
			strcpy(desc, VERB);
			break;
		case 's':
			switch (word[i-1]) {
				case 'i':
				case 'a':
				case 'o':
				case 'u':
					verb_exc = true;
					strcpy(desc, VERB);
					i--;
				default:
					break;
			}
			break;
		default:
			match = false;
			break;
	}
	if (match) {
		if (verb_exc) {
			sprintf(ptrs->descs[j++], "%s (%s)", word + i, desc); 
		} else {
			sprintf(ptrs->descs[j++], "%c (%s)", word[i], desc);
		}
		i--;
	}
	
	word[i--] = '\0';
	
	ptrs->word = word;
	ptrs->i = i;
	ptrs->j = j;
}
