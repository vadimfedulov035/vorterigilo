#include "apriori.h"


char correlatives[CORRELATIVES_NUM*2][WORD_LEN] = {
	// CORRELATIVE PRONOUNS/DETERMINERS:
	// INTERROGATIVE, RELATIVE,  DEMONSTRATIVE,
	// INDEFINITE,    UNIVERSAL, NEGATIVE
	
	// CORRELATIVE PRONOUNS
	"kio?",     "what"                 INTER     PRO      NOM,
	"kio",      "what"                 RELAT     PRO      NOM,
	"tio",      "that"                 DEMON     PRO      NOM,
	"io",       "something"            INDEF     PRO      NOM,
	"ĉio",      "everything"           UNIVE     PRO      NOM,
	"nenio",    "nothing"              NEGAT     PRO      NOM,

	"kion?",    "what"                 INTER     PRO      ACC,
	"kion",     "what"                 RELAT     PRO      ACC,
	"tion",     "that"                 DEMON     PRO      ACC,
	"ion",      "something"            INDEF     PRO      ACC,
	"ĉion",     "everything"           UNIVE     PRO      ACC,
	"nenion",   "nothing"              NEGAT     PRO      ACC,


	// CORRELATIVE SELECTIVE PRONOUNS (AS SUBSTANTIVES)
	// (flag ! if no substantive after pronouns)
	// (flag ! if no substantive before/after relative pronouns)
	"kiu?!",    "who/which one"        INTER SEL PRO SING NOM,
	"kiu!",     "who"                  RELAT SEL PRO SING NOM,
	"tiu!",     "that one"             DEMON SEL PRO SING NOM,
	"iu!",      "someone"              INDEF SEL PRO SING NOM,
	"ĉiu!",     "each one"             UNIVE SEL PRO SING NOM,
	"neniu!",   "no one"               NEGAT SEL PRO SING NOM,

	"kiuj?!",   "who/which ones"       INTER SEL PRO PLUR NOM,
	"kiuj!",    "who"                  RELAT SEL PRO PLUR NOM,
	"tiuj!",    "those"                DEMON SEL PRO PLUR NOM,
	"iuj!",     "some"                 INDEF SEL PRO PLUR NOM,
	"ĉiuj!",    "everyone"             UNIVE SEL PRO PLUR NOM,
	"neniuj!",  "no one"               NEGAT SEL PRO PLUR NOM,

	"kiun?!",   "whom/which one"       INTER SEL PRO SING ACC,
	"kiun!",    "whom"                 RELAT SEL PRO SING ACC,
	"tiun!",    "that one"             DEMON SEL PRO SING ACC,
	"iun!",     "someone"              INDEF SEL PRO SING ACC,
	"ĉiun!",    "each one"             UNIVE SEL PRO SING ACC,
	"neniun!",  "no one"               NEGAT SEL PRO SING ACC,

	"kiujn?!",  "whom/which ones"      INTER SEL PRO PLUR ACC,
	"kiujn!",   "whom"                 RELAT SEL PRO PLUR ACC,
	"tiujn!",   "those"                DEMON SEL PRO PLUR ACC,
	"iujn!",    "some"                 INDEF SEL PRO PLUR ACC,
	"ĉiujn!",   "everyone"             UNIVE SEL PRO PLUR ACC,
	"neniujn!", "none"                 NEGAT SEL PRO PLUR ACC,

	// CORRELATIVE SELECTIVE DETERMINERS
	"kiu?",     "which"                INTER SEL DET SING NOM,
	"kiu",      "who/that"             RELAT SEL DET SING NOM,
	"tiu",      "that"                 DEMON SEL DET SING NOM,
	"iu",       "some"                 INDEF SEL DET SING NOM,
	"ĉiu",      "each"                 UNIVE SEL DET SING NOM,
	"neniu",    "no"                   NEGAT SEL DET SING NOM,

	"kiuj?",    "which"                INTER SEL DET PLUR NOM,
	"kiuj",     "who/that"             RELAT SEL DET PLUR NOM,
	"tiuj",     "those"                DEMON SEL DET PLUR NOM,
	"iuj",      "some"                 INDEF SEL DET PLUR NOM,
	"ĉiuj",     "all"                  UNIVE SEL DET PLUR NOM,
	"neniuj",   "no"                   NEGAT SEL DET PLUR NOM,

	"kiun?",    "which"                INTER SEL DET SING ACC,
	"kiun",     "who/that"             RELAT SEL DET SING ACC,
	"tiun",     "that"                 DEMON SEL DET SING ACC,
	"iun",      "some"                 INDEF SEL DET SING ACC,
	"ĉiun",     "each"                 UNIVE SEL DET SING ACC,
	"neniun",   "no"                   NEGAT SEL DET SING ACC,

	"kiujn?",   "which"                INTER SEL DET PLUR ACC,
	"kiujn",    "who/that"             RELAT SEL DET PLUR ACC,
	"tiujn",    "those"                DEMON SEL DET PLUR ACC,
	"iujn",     "some"                 INDEF SEL DET PLUR ACC,
	"ĉiujn",    "all"                  UNIVE SEL DET PLUR ACC,
	"neniujn",  "no"                   NEGAT SEL DET PLUR ACC,


	// CORRELATIVE DESCRIPTIVE PRONOUNS (AS SUBSTANTIVES)
	// (flag ! if no substantive after pronouns)
	// (flag ! if no substantive before/after relative pronouns)
	"kia?!",    "what kind of"         INTER DES PRO SING NOM,
	"kia!",     "what"                 RELAT DES PRO SING NOM,
	"tia!",     "like that"            DEMON DES PRO SING NOM,
	"ia!",      "sort of"              INDEF DES PRO SING NOM,
	"ĉia!",     "all kinds of"         UNIVE DES PRO SING NOM,
	"nenia!",   "not even one"         NEGAT DES PRO SING NOM,

	"kiaj?!",   "what kind of"         INTER DES PRO PLUR NOM,
	"kiaj!",    "what"                 RELAT DES PRO PLUR NOM,
	"tiaj!",    "like that"            DEMON DES PRO PLUR NOM,
	"iaj!",     "sort of"              INDEF DES PRO PLUR NOM,
	"ĉiaj!",    "all kinds of"         UNIVE DES PRO PLUR NOM,
	"neniaj!",  "not even one"         NEGAT DES PRO PLUR NOM,

	"kian?!",   "what kind of"         INTER DES PRO SING ACC,
	"kian!",    "what"                 RELAT DES PRO SING ACC,
	"tian!",    "like that"            DEMON DES PRO SING ACC,
	"ian!",     "sort of"              INDEF DES PRO SING ACC,
	"ĉian!",    "all kinds of"         UNIVE DES PRO SING ACC,
	"nenian!",  "not even one"         NEGAT DES PRO SING ACC,

	"kiajn?!",  "what kind of"         INTER DES PRO PLUR ACC,
	"kiajn!",   "what"                 RELAT DES PRO PLUR ACC,
	"tiajn!",   "like that"            DEMON DES PRO PLUR ACC,
	"iajn!",    "sort of"              INDEF DES PRO PLUR ACC,
	"ĉiajn!",   "all kinds of"         UNIVE DES PRO PLUR ACC,
	"neniajn!", "none"                 NEGAT DES PRO PLUR ACC,
	
	// CORRELATIVE DESCRIPTIVE DETERMINERS 
	"kia?",     "what kind of"         INTER DES DET SING NOM,
	"kia",      "what a"               RELAT DES DET SING NOM,
	"tia",      "such a"               DEMON DES DET SING NOM,
	"ia",       "sort of"              INDEF DES DET SING NOM,
	"ĉia",      "all kinds"            UNIVE DES DET SING NOM,
	"nenia",    "not even one"         NEGAT DES DET SING NOM,

	"kiaj?",    "what kind of"         INTER DES DET PLUR NOM,
	"kiaj",     "what"                 RELAT DES DET PLUR NOM,
	"tiaj",     "such"                 DEMON DES DET PLUR NOM,
	"iaj",      "sort of"              INDEF DES DET PLUR NOM,
	"ĉiaj",     "all kinds"            UNIVE DES DET PLUR NOM,
	"neniaj",   "not even one"         NEGAT DES DET PLUR NOM,

	"kian?",    "what kind of"         INTER DES DET SING ACC,
	"kian",     "what a"               RELAT DES DET SING ACC,
	"tian",     "such a"               DEMON DES DET SING ACC,
	"ian",      "sort of"              INDEF DES DET SING ACC,
	"ĉian",     "all kinds"            UNIVE DES DET SING ACC,
	"nenian",   "not even one"         NEGAT DES DET SING ACC,

	"kiajn?",   "what kind of"         INTER DES DET PLUR ACC,
	"kiajn",    "what"                 RELAT DES DET PLUR ACC,
	"tiajn",    "such"                 DEMON DES DET PLUR ACC,
	"iajn",     "sort of"              INDEF DES DET PLUR ACC,
	"ĉiajn",    "all kinds"            UNIVE DES DET PLUR ACC,
	"neniajn",  "not even one"         NEGAT DES DET PLUR ACC,


	// CORRELATIVE POSSESSIVE PRONOUNS 
	"kies?!",   "whose"                INTER POS PRO      RGEN,
	"kies!",    "whose"                RELAT POS PRO      RGEN,
	"ties!",    "their\'s"             DEMON POS PRO      RGEN,
	"ies!",     "someone\'s"           INDEF POS PRO      RGEN,
	"ĉies!",    "everyone\'s"          UNIVE POS PRO      RGEN,
	"nenies!",  "no one\'s"            NEGAT POS PRO      RGEN,

	// CORRELATIVE POSSESSIVE DETERMINERS 
	"kies?",    "whose"                INTER POS DET      RGEN,
	"kies",     "whose"                RELAT POS DET      RGEN,
	"ties",     "their\'s"             DEMON POS DET      RGEN,
	"ies",      "someone\'s"           INDEF POS DET      RGEN,
	"ĉies",     "everyone\'s"          UNIVE POS DET      RGEN,
	"nenies",   "no one\'s"            NEGAT POS DET      RGEN,


	// CORRELATIVE ADVERBS OF PLACE
	"kie?",     "where"                INTER ADV PLACE,
	"kie",      "where"                RELAT ADV PLACE,
	"tie",      "there"                DEMON ADV PLACE,
	"ie",       "somewhere"            INDEF ADV PLACE,
	"ĉie",      "everywhere"           UNIVE ADV PLACE,
	"nenie",    "nowhere"              NEGAT ADV PLACE,


	// CORRELATIVE ADVERBS OF MOTION
	"kien?",    "where"                INTER ADV MOTION,
	"kien",     "where"                RELAT ADV MOTION,
	"tien",     "there"                DEMON ADV MOTION,
	"ien",      "somewhere"            INDEF ADV MOTION,
	"ĉien",     "everywhere"           UNIVE ADV MOTION,
	"nenien",   "nowhere"              NEGAT ADV MOTION,


	// CORRELATIVE ADVERBS OF TIME
	"kiam?",    "when"                 INTER ADV TIME,
	"kiam",     "when"                 RELAT ADV TIME,
	"tiam",     "then"                 DEMON ADV TIME,
	"iam",      "ever"                 INDEF ADV TIME,
	"ĉiam",     "always"               UNIVE ADV TIME,
	"neniam",   "never"                NEGAT ADV TIME,


	// CORRELATIVE ADVERBS OF MANNER
	"kiel?",    "how"                  INTER ADV MANNER,
	"kiel",     "how"                  RELAT ADV MANNER,
	"tiel",     "like that"            DEMON ADV MANNER,
	"iel",      "somehow"              INDEF ADV MANNER,
	"ĉiel",     "in every way"         UNIVE ADV MANNER,
	"neniel",   "no way"               NEGAT ADV MANNER,


	// CORRELATIVE ADVERBS OF REASON
	"kial?",    "why"                  INTER ADV REASON,
	"kial",     "why"                  RELAT ADV REASON,
	"tial",     "thats why"            DEMON ADV REASON,
	"ial",      "for some reason"      INDEF ADV REASON,
	"ĉial",     "for whatever reason"  UNIVE ADV REASON,
	"nenial",   "for no reason"        NEGAT ADV REASON,


	// CORRELATIVE ADVERBS OF AMOUNT
	"kiom?",    "how many"             INTER ADV AMOUNT,
	"kiom",     "how many"             RELAT ADV AMOUNT,
	"tiom",     "so many"              DEMON ADV AMOUNT,
	"iom",      "kinda"                INDEF ADV AMOUNT,
	"ĉiom",     "all of it"            UNIVE ADV AMOUNT,
	"neniom",   "none"                 NEGAT ADV AMOUNT,
};
