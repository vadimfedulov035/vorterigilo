#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../hashmap/hashmap.h"
#include "vocab.h"

#include "../base/base.h"
#include "../morph/morph.h"


int vocab_compare(const void *a, const void *b, void *udata) {
    const struct VocabUnit *ua = a;
    const struct VocabUnit *ub = b;
    return strcmp(ua->word, ub->word);
}

bool vocab_iter(const void *item, void *udata) {
    const struct VocabUnit *vocabUnit = item;
    printf("%s - %s (%s)\n",
	vocabUnit->word, vocabUnit->transl, vocabUnit->def);
    return true;
}

uint64_t vocab_hash(const void *item, uint64_t seed0, uint64_t seed1) {
    const struct VocabUnit *vocabUnit = item;
    return hashmap_sip(vocabUnit->word, strlen(vocabUnit->word), seed0, seed1);
}

void vocab_set(struct hashmap* map, char *arr[]) {
	for(int i = 0; arr[i] != NULL; i = i + 3) {
		hashmap_set(map,
		&(struct VocabUnit){ .word=arr[i], .transl=arr[i+1], .def=arr[i+2]});
	}
}

struct hashmap* init_base_vocab() {
    struct hashmap *map = hashmap_new(sizeof(struct VocabUnit), 0, 0, 0,
                            vocab_hash, vocab_compare, NULL, NULL);

    vocab_set(map, pronouns);
    vocab_set(map, numerals);
    vocab_set(map, correlatives);
    vocab_set(map, functors);
    vocab_set(map, abbreviations);

    return map;
}

struct hashmap* init_morph_vocab() {
	struct hashmap *map = hashmap_new(sizeof(struct VocabUnit), 0, 0, 0,
							vocab_hash, vocab_compare, NULL, NULL);

	vocab_set(map, verb_endings);
	vocab_set(map, suffixes);
	vocab_set(map, prefixes);

	return map;
}
