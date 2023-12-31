#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NB_WORDS 10


static const char * translationTable[NB_WORDS][2] = {
	{ "zero" , "zero" },
        { "one" , "un" },
        { "two" , "deux" },
        { "three" , "trois" },
        { "four" , "quatre" },
        { "five" , "cinq" },
        { "six" , "six" },
        { "seven" , "sept" },
        { "eight" , "huit" },
        { "nine" , "neuf" }
};

char *translate_word(const char *word) {
    for (int i = 0; i < NB_WORDS; ++i) {
        if (strcmp(word, translationTable[i][0]) == 0) {
            return strdup(translationTable[i][1]);
        }
    }
    return strdup(word); // Return a copy of the original word if not found
}

char *translate_sentence(const char *sentence) {
    const int maxTranslationSize = strlen(sentence) * 5; // Maximum size for translation
    char *result = (char *)malloc((maxTranslationSize + 1) * sizeof(char));
    result[0] = '\0'; // Initialize result as an empty string

    char *token = strtok((char *)sentence, " "); // Tokenizing the sentence
    while (token != NULL) {
        char *translated_word = translate_word(token);
        if (strlen(result) + strlen(translated_word) + 1 <= maxTranslationSize) {
            strcat(result, translated_word);
            strcat(result, " ");
        } else {
            break; // Stop adding translations if exceeding maximum size
        }
        free(translated_word);
        token = strtok(NULL, " ");
    }

    // Remove the trailing space if present
    if (strlen(result) > 0 && result[strlen(result) - 1] == ' ') {
        result[strlen(result) - 1] = '\0';
    }

    return result;
}



int main(void){

	printf("Word and sentence translation program\n");
	printf("\n");


	char input_word[100];
	printf("Enter a single word to translate: ");
	scanf("%s", input_word);

	char* translated_word = translate_word(input_word);
	printf("Translation is: %s\n", translated_word);
	free(translated_word);

	printf("\n");
	getchar(); // Consume the newline character

	char input[1000];
	printf("Enter a sentence to translate: ");
	fgets(input, sizeof(input), stdin);

	// Remove newline character if present
	if (input[strlen(input) - 1] == '\n') {
		input[strlen(input) - 1] = '\0';
	}

	char *translation = translate_sentence(input);
	printf("Translation is: %s\n", translation);

	free(translation); // Free allocated memory

	return 0;

 //End of the program
}

