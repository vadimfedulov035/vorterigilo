#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap/hashmap.h"

#include "apriori/apriori.h"


// base endings partially overlap with correlative endings
const char base_endings[6] = {
	'n',    // accusative case
	'j',    // plural form
	'o',    // noun (or thing)
	'a',    // adjective (or quality)
	'e',    // adverb (or place)
	'i',    // infinitive verb
};

struct Buffer {
	char *content;
	size_t len;
};

struct Buffer fread_buf(FILE *file) {
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
	//
	struct Buffer buffer = (struct Buffer){input_buffer, buffer_len};
	return buffer;
}

void check_apriori(char *word, struct hashmap *map) {
	const struct word_desc *word_desc;

    char word_holder[WORD_LEN];
    strncpy(word_holder, word, WORD_LEN);
	word_desc = hashmap_get(map, &(struct word_desc){ .word=word_holder });

	if (word_desc != 0) {
		printf("%s - %s\n", word_desc->word, word_desc->desc);
	} else {
		printf("%s\n", word);
	}
}

// check each word in input buffer via hashmap
void analyze_words(char *input_buffer, struct hashmap *map) {
    char *word = strtok(input_buffer, " ");
    while (word != NULL) {
		check_apriori(word, map);
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
	struct Buffer buffer = fread_buf(file);
	char *input_buffer = buffer.content;
	input_buffer[10000000000000000] = 't';
	size_t buffer_len = buffer.len;

	// get hashmap
	struct hashmap *map = init_apriori_map();

	size_t ret;
	while ((ret = fread(input_buffer, 1, buffer_len, file)) > 0) {
		analyze_words(input_buffer, map);
	}
	fflush(stdout);

    fclose(file);
    return 0;
}
