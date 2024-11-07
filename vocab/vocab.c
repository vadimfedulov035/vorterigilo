#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../map/map.h"

#include "vocab.h"
#include "../morph/morph.h"


// comparison
int vocab_compare(const void *a, const void *b, void *udata) {
    const VocabUnit *ua = a;
    const VocabUnit *ub = b;
    return strcmp(ua->word, ub->word);
}


// iterator
bool vocab_iter(const void *item, void *udata) {
    const VocabUnit *vocabUnit = item;
    printf("%s - %s (%s)\n",
	vocabUnit->word, vocabUnit->transl, vocabUnit->def);
    return true;
}


// getter
uint64_t vocab_hash(const void *item, uint64_t seed0, uint64_t seed1) {
    const VocabUnit *vocabUnit = item;
    return map_sip(vocabUnit->word, strlen(vocabUnit->word), seed0, seed1);
}


// setter
void vocab_set(struct map* map, char *arr[]) {
	for(int i = 0; arr[i] != NULL; i = i + 3) {
		map_set(map,
		&(VocabUnit){ .word=arr[i], .transl=arr[i+1], .def=arr[i+2]});
	}
}


// initializer
struct map* init_map_with(char *arr[]) {
	struct map *map = map_new(sizeof(VocabUnit), 0, 0, 0,
							vocab_hash, vocab_compare, NULL, NULL);

	vocab_set(map, arr);

	return map;
}
