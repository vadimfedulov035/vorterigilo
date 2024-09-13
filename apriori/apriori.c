#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../hashmap/hashmap.h"

#include "apriori.h"


int word_desc_compare(const void *a, const void *b, void *udata) {
    const struct word_desc *ua = a;
    const struct word_desc *ub = b;
    return strcmp(ua->word, ub->word);
}

bool word_desc_iter(const void *item, void *udata) {
    const struct word_desc *word_desc = item;
    printf("%s (desc=%s)\n", word_desc->word, word_desc->desc);
    return true;
}

uint64_t word_desc_hash(const void *item, uint64_t seed0, uint64_t seed1) {
    const struct word_desc *word_desc = item;
    return hashmap_sip(word_desc->word, strlen(word_desc->word), seed0, seed1);
}

void word_desc_set(struct hashmap* map, char (*arr)[WORD_LEN], int num) {
	for(int i = 0; i < (num * 2); i = i + 2) {
		hashmap_set(map,
		&(struct word_desc){ .word=arr[i], .desc=arr[i+1]});
	}
}

struct hashmap* init_apriori_map() {
	struct hashmap *map = hashmap_new(sizeof(struct word_desc), 0, 0, 0,
							word_desc_hash, word_desc_compare, NULL, NULL);

	word_desc_set(map, pronouns,       PRONOUNS_NUM);
	word_desc_set(map, numerals,       NUMERALS_NUM);
	word_desc_set(map, correlatives,   CORRELATIVES_NUM);
	word_desc_set(map, function_words, FUNCTION_WORDS_NUM);
	word_desc_set(map, abbreviations,  ABBREVIATIONS_NUM);

	//printf("\n-- iterate over all users (hashmap_iter) --\n");
    //size_t iter = 0;
    //void *item;
    //while (hashmap_iter(map, &iter, &item)) {
    //  const struct word_desc *word_desc = item;
    //  printf("%s - %s\n", word_desc->word, word_desc->desc);
    //}
	//exit(0);

	return map;
}
