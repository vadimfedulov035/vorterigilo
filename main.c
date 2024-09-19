#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashmap/hashmap.h"
#include "vocab/vocab.h"

#include "base/base.h"
#include "morph/morph.h"


struct buffer {
	char *content;
	size_t len;
};

struct Vocabs {
	struct hashmap *base_vocab;
	struct hashmap *morph_vocab;
};

struct buffer fread_buf(FILE *file) {
	// fully bufferize file
    fseek(file, 0, SEEK_END);
    size_t file_len = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *input_buffer = malloc(file_len * 100);
    char *output_buffer = malloc(file_len * 100);
	// use static buffer size if cannot fully bufferize file
	size_t buffer_len = file_len;
    if (input_buffer == NULL || output_buffer == NULL) {
		exit(0);
		buffer_len = 32768;
		input_buffer = malloc(buffer_len);
		output_buffer = malloc(buffer_len);
	}
	// set output buffer
	setvbuf(stdout, output_buffer, _IOFBF, buffer_len);
	// return input buffer
	struct buffer buffer = (struct buffer){input_buffer, buffer_len};
	return buffer;
}

void check_suffixes(struct Pointers *ptrs, struct hashmap *morph_vocab) {
	char *word = ptrs->word;
	int i = ptrs->i;
	int j = ptrs->j;
	// word is read backwards, descriptions are written forwards
	const struct VocabUnit *res;
	while (i >= 0) {
		res = hashmap_get(morph_vocab, &(struct VocabUnit){ .word=word + i });
		if (res != 0) {
			sprintf(ptrs->descs[j++],
			"%s - %s (%s)", res->word, res->transl, res->def); 
			word[i] = '\0';
		}
		i--;
	}
	sprintf(ptrs->descs[j++], "%s - ? (?)", word); 
	ptrs->word = word;
	ptrs->i = i;
	ptrs->j = j;
}

void morph_check(char *word, struct hashmap *morph_vocab) {
	char (*descs)[DESC_LEN] = malloc(DESC_NUM * sizeof(*descs));
    for (int i = 0; i < DESC_NUM; i++) {
        descs[i][0] = '\0';
    }

	struct Pointers *ptrs = malloc(sizeof(struct Pointers));
	ptrs->word = word; 
	ptrs->i = strlen(word) - 1;
	ptrs->descs = descs;
	ptrs->j = 0;
	
	check_endings(ptrs);
	// check_suffixes(ptrs, morph_vocab);

	// read descriptions backwards
	descs = ptrs->descs;
	for (int i = DESC_NUM - 1; i >= 0; i--) {
		if (strlen(descs[i]) != 0) {
			printf("%s\n", descs[i]);
		}
	}

    free(ptrs);
}

int base_check(char *word, struct hashmap *base_vocab) {
	bool match = false;
	const struct VocabUnit *res;
	res = hashmap_get(base_vocab, &(struct VocabUnit){ .word=word });
	if (res != 0) {
		match = true;
		printf("%s - %s (%s)\n", res->word, res->transl, res->def);
	}
	return match;
}

void analyze(char *input_buffer, struct Vocabs *vocabs) {
	struct hashmap *base_vocab = vocabs->base_vocab;
	struct hashmap *morph_vocab = vocabs->morph_vocab;
    char *word = strtok(input_buffer, " ");
    while (word != NULL) {
		bool match = base_check(word, base_vocab);
		if (!match) {
			morph_check(word, morph_vocab);
		}
        word = strtok(NULL, " ");
    }
}

int main() {
	// open and read file into buffer
    FILE *file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
	struct buffer buffer = fread_buf(file);
	char *input_buffer = buffer.content;
	size_t input_buffer_len = buffer.len;

	// get maps and unite them
	struct hashmap *base_vocab = init_base_vocab();
	struct hashmap *morph_vocab = init_morph_vocab();
	struct Vocabs *vocabs = malloc(sizeof(struct Vocabs));
	vocabs->base_vocab = base_vocab;
	vocabs->morph_vocab = morph_vocab;

	// check each word against maps
	size_t ret;
	while ((ret = fread(input_buffer, 1, input_buffer_len, file)) > 0) {
		analyze(input_buffer, vocabs);
	}
	fflush(stdout);

	// gracefully exit
    fclose(file);
    return 0;
}
