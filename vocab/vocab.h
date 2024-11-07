#ifndef VOCAB_H
#define VOCAB_H

#include "../map/map.h"

typedef struct VocabUnit {
    char *word;
	char *transl;
    char *def;
} VocabUnit;

struct map *init_map_with();

#endif
