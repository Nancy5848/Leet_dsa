#include <string.h>

int findMinimumOperations(char* s1, char* s2, char* s3) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int n3 = strlen(s3);

    int i = 0;

    // Find the common prefix
    while (i < n1 && i < n2 && i < n3 &&
           s1[i] == s2[i] && s2[i] == s3[i]) {
        i++;
    }

    // If no common character exists, impossible
    if (i == 0) {
        return -1;
    }

    // Number of characters to delete
    int operations = (n1 - i) + (n2 - i) + (n3 - i);

    return operations;
}