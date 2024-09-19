#include "base.h"


char *pronouns[] = {
	// PERSONAL PRONOUNS
	// PERSONAL SUBJECT PRONOUNS
    "mi",    "I",                  PERS   SUB PRO      FIR  SING    NOM,
	"ni",    "we",                 PERS   SUB PRO      FIR  PLUR    NOM,
	"vi",    "you",                PERS   SUB PRO      SEC  UN      NOM,
	"li",    "he",                 PERS   SUB PRO      THI  SING M  NOM,
	"ŝi",    "she",                PERS   SUB PRO      THI  SING F  NOM,
	"ĝi",    "it",                 PERS   SUB PRO      THI  SING N  NOM,
    "ŝli",   "they",               PERS   SUB PRO      THI  SING EP NOM,
	"ri",    "they",               PERS   SUB PRO      THI  SING EP NOM,
	"ili",   "they",               PERS   SUB PRO      THI  PLUR    NOM,

	// PERSONAL OBJECT PRONOUNS
	"min",   "me",                 PERS   OBJ PRO      FIR  SING    ACC,
	"nin",   "us",                 PERS   OBJ PRO      FIR  PLUR    ACC,
	"vin",   "you",                PERS   OBJ PRO      SEC  UN      ACC,
	"lin",   "him",                PERS   OBJ PRO      THI  SING M  ACC,
	"ŝin",   "her",                PERS   OBJ PRO      THI  SING F  ACC,
	"ĝin",   "it",                 PERS   OBJ PRO      THI  SING N  ACC,
    "ŝlin",  "them",               PERS   OBJ PRO      THI  SING EP ACC,
	"rin",   "them",               PERS   OBJ PRO      THI  SING EP ACC,
	"ilin",  "them",               PERS   OBJ PRO      THI  PLUR    ACC,

	// REFLEXIVE PRONOUNS
	// (flag second match of pronoun)
	"min!",  "myself",             PERS   REF PRO      FIR  SING    ACC,
	"nin!",  "ourselves",          PERS   REF PRO      FIR  PLUR    ACC,
 	"vin!",  "yourself",           PERS   REF PRO      SEC  UN      ACC,
 	"sin",   THISELF,              PERS   REF PRO      THI  SING EP ACC,
 
 
 	// PERSONAL POSSESSIVE PRONOUNS
 	// (flag if no noun after)
 	"mia!",   "my",                PERS  POS PRO      FIR  SING    NOM,
	"nia!",   "our",               PERS  POS PRO      FIR  PLUR    NOM,
	"via!",   "your",              PERS  POS PRO      SEC  UN      NOM,
	"lia!",   "his",               PERS  POS PRO      THI  SING M  NOM,
	"ŝia!",   "her",               PERS  POS PRO      THI  SING F  NOM,
	"ĝia!",	  "its",               PERS  POS PRO      THI  SING N  NOM,
    "ŝlia!",  "their",             PERS  POS PRO      THI  SING EP NOM,
	"ria!",   "their",             PERS  POS PRO      THI  SING EP NOM,
	"ilia!",  "their",             PERS  POS PRO      THI  PLUR    NOM,
      
	"mian!",  "my",                PERS  POS PRO      FIR  SING    ACC,
	"nian!",  "our",               PERS  POS PRO      FIR  PLUR    ACC,
	"vian!",  "your",              PERS  POS PRO      SEC  UN      ACC,
	"lian!",  "his",               PERS  POS PRO      THI  SING M  ACC,
	"ŝian!",  "her",               PERS  POS PRO      THI  SING F  ACC,
	"ĝian!",  "its",               PERS  POS PRO      THI  SING N  ACC,
    "ŝlian!", "their",             PERS  POS PRO      THI  SING EP ACC,
	"rian!",  "their",             PERS  POS PRO      THI  SING EP ACC,
	"ilian!", "their",             PERS  POS PRO      THI  PLUR    ACC,
      
	"mies!",  "mine",              PERS  POS PRO FORM FIR  SING    RGEN,
	"nies!",  "ours",              PERS  POS PRO FORM FIR  PLUR    RGEN,
	"vies!",  "yours",             PERS  POS PRO FORM SEC  UN      RGEN,
	"lies!",  "his",               PERS  POS PRO FORM THI  SING M  RGEN,
	"ŝies!",  "hers",              PERS  POS PRO FORM THI  SING F  RGEN,
	"ĝies!",  "its",               PERS  POS PRO FORM THI  SING N  RGEN,
    "ŝlies!", "theirs",            PERS  POS PRO FORM THI  SING EP RGEN,
	"ries!",  "theirs",            PERS  POS PRO FORM THI  SING EP RGEN,
	"ilies!", "theirs",            PERS  POS PRO FORM THI  PLUR    RGEN,

	// PERSONAL POSSESSIVE DETERMINERS
	"mia",   "my",                 PERS  POS DET      FIR  SING    NOM,
	"nia",   "our",                PERS  POS DET      FIR  PLUR    NOM,
	"via",   "your",               PERS  POS DET      SEC  UN      NOM,
	"lia",   "his",                PERS  POS DET      THI  SING M  NOM,
	"ŝia",   "her",                PERS  POS DET      THI  SING F  NOM,
	"ĝia",	 "its",                PERS  POS DET      THI  SING N  NOM,
    "ŝlia",  "their",              PERS  POS DET      THI  SING EP NOM,
	"ria",   "their",              PERS  POS DET      THI  SING EP NOM,
	"ilia",	 "their",              PERS  POS DET      THI  PLUR    NOM,
       
	"mian",  "my",                 PERS  POS DET      FIR  SING    ACC,
	"nian",	 "our",                PERS  POS DET      FIR  PLUR    ACC,
	"vian",	 "your",               PERS  POS DET      SEC  UN      ACC,
	"lian",	 "his",                PERS  POS DET      THI  SING M  ACC,
	"ŝian",	 "her",                PERS  POS DET      THI  SING F  ACC,
	"ĝian",	 "its",                PERS  POS DET      THI  SING N  ACC,
    "ŝlia",  "their",              PERS  POS DET      THI  SING EP ACC,
	"ria",   "their",              PERS  POS DET      THI  SING EP ACC,
	"ilian", "their",              PERS  POS DET      THI  PLUR    ACC,

	"mies",  "mine",               PERS  POS DET FORM FIR  SING    RGEN,
	"nies",	 "ours",               PERS  POS DET FORM FIR  PLUR    RGEN,
	"vies",	 "yours",              PERS  POS DET FORM SEC  UN      RGEN,
	"lies",	 "his",                PERS  POS DET FORM THI  SING M  RGEN,
	"ŝies",	 "hers",               PERS  POS DET FORM THI  SING F  RGEN,
	"ĝies",	 "its",                PERS  POS DET FORM THI  SING N  RGEN,
    "ŝlies", "theirs",             PERS  POS DET FORM THI  SING EP RGEN,
	"ries",  "theirs",             PERS  POS DET FORM THI  SING EP RGEN,
	"ilies", "theirs",             PERS  POS DET FORM THI  PLUR    RGEN,


	// INDEFINITE PRONOUNS
	// INDEFINITE SUBJECT PRONOUNS
    "oni",   "one",                INDEF SUB PRO      THI  UN   EP NOM,

	// INDEFINITE OBJECT PRONOUNS
	"onin",  "one",                INDEF OBJ PRO      THI  UN   EP ACC,

	// INDEFINITE POSSESSIVE PRONOUNS
	"onia",  "one\'s",             INDEF POS PRO      THI  UN   EP NOM,
	"onian", "one\'s",             INDEF POS PRO      THI  UN   EP ACC,
	"onies", "one\'s",             INDEF POS PRO      THI  UN   EP RGEN,

	// INDEFINITE POSSESSIVE DETERMINERS
	"onia",  "one\'s",             INDEF POS DET      THI  UN   EP NOM,
	"onian", "one\'s",             INDEF POS DET      THI  UN   EP ACC,
	"onies", "one\'s",             INDEF POS DET      THI  UN   EP RGEN,


	// MULTAL PRONOUNS
	// (flag if no noun after)
	"multe!",      "much",         MULT         PRO                     UC,
	"pli!",        "more",         MULT         PRO                     UC,
	"plej!",       "most",         MULT         PRO                     UC,
	"multaj!",     "many",         MULT         PRO                     NOM,
	"multajn!",    "many",         MULT         PRO                     ACC,

	// MULTAL DETERMINERS
	// (no flag if noun after)
	"multe",       "much",         MULT         DET                     UC,
	"pli",         "more",         MULT         DET                     UC,
	"plej",        "most",         MULT         DET                     UC,
	"multaj",      "many",         MULT         DET                     NOM,
	"multajn",     "many",         MULT         DET                     ACC,


	// PAUCAL PRONOUNS
	// (flag if no noun after)
	"malmulte!",   "little",       PAUC         PRO                     UC,
	"malpli!",     "fewer/less",   PAUC         PRO                     UC,
	"malplej!",    "fewest/least", PAUC         PRO                     UC,
	"malmultaj!",  "few/little",   PAUC         PRO                     NOM,
	"malmultajn!", "few/little",   PAUC         PRO                     ACC,

	// PAUCAL DETERMINERS
	// (flag if no noun after)
	"malmulte",    "little",       PAUC         DET                     UC,
	"malpli",      "fewer/less",   PAUC         DET                     UC,
	"malplej",     "fewest/least", PAUC         DET                     UC,
	"malmultaj",   "few/little",   PAUC         DET                     NOM,
	"malmultajn",  "few/little",   PAUC         DET                     ACC,

	NULL,
};
