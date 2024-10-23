#ifndef VOCAB_H
#define VOCAB_H

#include "../hashmap/hashmap.h"

typedef struct VocabUnit {
    char *word;
	char *transl;
    char *def;
} VocabUnit;

typedef struct hashmap Map;

typedef struct Maps {
    Map *base_map;
    Map *root_map;
    Map *pre_map;
    Map *post_map;
} Maps;

Map* init_base_map();
Map* init_map_with();

#endif
