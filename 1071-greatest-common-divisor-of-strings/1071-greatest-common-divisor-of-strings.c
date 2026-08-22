#include <string.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {
    int n1 = strlen(str1);
    int n2 = strlen(str2);

    // Check if a common divisor string is possible
    for (int i = 0; i < n1 + n2; i++) {
        // This check is done below using concatenation logic
    }

    // str1 + str2 must equal str2 + str1
    char* temp1 = (char*)malloc((n1 + n2 + 1) * sizeof(char));
    char* temp2 = (char*)malloc((n1 + n2 + 1) * sizeof(char));

    strcpy(temp1, str1);
    strcat(temp1, str2);

    strcpy(temp2, str2);
    strcat(temp2, str1);

    if (strcmp(temp1, temp2) != 0) {
        free(temp1);
        free(temp2);

        char* result = (char*)malloc(1);
        result[0] = '\0';
        return result;
    }

    // Length of the largest common divisor string
    int len = gcd(n1, n2);

    char* result = (char*)malloc((len + 1) * sizeof(char));

    strncpy(result, str1, len);
    result[len] = '\0';

    free(temp1);
    free(temp2);

    return result;
}