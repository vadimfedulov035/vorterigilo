#ifndef VOCAB_H
#define VOCAB_H

#include "../hashmap/hashmap.h"


struct VocabUnit {
    char *word;
	char *transl;
    char *def;
};

struct hashmap* init_base_vocab();
struct hashmap* init_morph_vocab();

#endif
