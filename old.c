#include <stdio.h>
#include <string.h>

#include "data/apriori.h"
#include "data/endings.h"
#include "data/suffixes.h"
#include "data/prefixes.h"

void find_suffixes(char *word) {
	int found = 0;
	int result[MAX_SUFFIXES] = {-1};
	int found_num = 0;
	do {
		found = 0; // reset flag
		size_t word_len = strlen(word);
		for (int i = 0; i < MAX_SUFFIXES; i++) {
			size_t suffix_len = strlen(suffixes[i]);
			// check for suffix
			int entailable = word_len >= suffix_len;
			int entails = strcmp(word + word_len - suffix_len, suffixes[i]) == 0;
			if (entailable && entails) {
				found = 1; // set flag
				result[found_num++] = i; // save id
				word[word_len - suffix_len] = '\0'; // rm suffix
				break;
			}
		}
	} while (found);

	printf("%s'", word);
	for (int i = found_num-1; i >= 0; i--) {
		int idx = result[i];
		if (idx != -1) {
			printf("%s", suffixes[idx]);
		}
		if (i != 0) {
			printf("'");
		}
	}
	printf("\n");
}

int main() {
	char text[1000];

	printf("Enter Esperanto text: ");
	fflush(stdout);
	fgets(text, sizeof(text), stdin); // Read a line of input including spaces

	// Remove the newline character if it exists
	text[strcspn(text, "\n")] = '\0';

	// get the first token
	char *word = strtok(text, " ");

	// walk through the other tokens
	while (word != NULL) {
		find_suffixes(word);
		word = strtok(NULL, " ");
	}

	return 0;
}
