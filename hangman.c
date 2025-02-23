#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 6

// Function to select a random word
const char* selectRandomWord(const char* wordList[], int wordCount) {
    srand(time(NULL));
    int randomIndex = rand() % wordCount;
    return wordList[randomIndex];
}

// Function to initialize the word with underscores
void initializeWord(char word[], int wordLength) {
    for (int i = 0; i < wordLength; i++) {
        word[i] = '_';
    }
    word[wordLength] = '\0';
}

// Function to display the current state of the word
void displayWord(const char word[], int wordLength) {
    for (int i = 0; i < wordLength; i++) {
        printf("%c ", word[i]);
    }
    printf("\n");
}

int main() {
    const char* wordList[] = {"hangman", "programming", "computer", "language", "coding"};
    int wordCount = sizeof(wordList) / sizeof(wordList[0]);

    const char* selectedWord = selectRandomWord(wordList, wordCount);
    int wordLength = strlen(selectedWord);
    
    char guessedWord[wordLength + 1];
    initializeWord(guessedWord, wordLength);

    int tries = 0;
    char guessedLetters[26]; // To store already guessed letters
    int guessedLetterCount = 0;

    while (1) {
        printf("\nTries left: %d\n", MAX_TRIES - tries);
        displayWord(guessedWord, wordLength);

        if (strcmp(selectedWord, guessedWord) == 0) {
            printf("Congratulations! You guessed the word: %s\n", selectedWord);
            break;
        }

        if (tries >= MAX_TRIES) {
            printf("Out of tries. The word was: %s\n", selectedWord);
            break;
        }

        char guess;
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        // Check if the letter has already been guessed
        int alreadyGuessed = 0;
        for (int i = 0; i < guessedLetterCount; i++) {
            if (guessedLetters[i] == guess) {
                alreadyGuessed = 1;
                break;
            }
        }

        if (alreadyGuessed) {
            printf("You've already guessed that letter. Try another one.\n");
            continue;
        }

        guessedLetters[guessedLetterCount++] = guess;

        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (selectedWord[i] == guess) {
                guessedWord[i] = guess;
                found = 1;
            }
        }

        if (!found) {
            printf("Incorrect guess!\n");
            tries++;
        }
    }

    return 0;
}
