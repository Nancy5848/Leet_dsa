#include <stdio.h>
#include <string.h>

int similarPairs(char** words, int wordsSize) {
    int count = 0;

    // Store the character mask of each word
    int mask[100];

    for (int i = 0; i < wordsSize; i++) {
        mask[i] = 0;

        for (int j = 0; words[i][j] != '\0'; j++) {
            int index = words[i][j] - 'a';

            // Set the bit for this character
            mask[i] |= (1 << index);
        }
    }

    // Compare every pair
    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if (mask[i] == mask[j]) {
                count++;
            }
        }
    }

    return count;
}