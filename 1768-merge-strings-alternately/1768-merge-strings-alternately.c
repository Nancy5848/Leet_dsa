#include <stdlib.h>
#include <string.h>

char* mergeAlternately(char* word1, char* word2) {
    int n = strlen(word1);
    int m = strlen(word2);

    // Maximum length = n + m
    char* result = (char*)malloc((n + m + 1) * sizeof(char));

    int i = 0, j = 0, k = 0;

    // Add characters alternately
    while (i < n && j < m) {
        result[k++] = word1[i++];
        result[k++] = word2[j++];
    }

    // Add remaining characters of word1
    while (i < n) {
        result[k++] = word1[i++];
    }

    // Add remaining characters of word2
    while (j < m) {
        result[k++] = word2[j++];
    }

    // Null terminator
    result[k] = '\0';

    return result;
}