// Next Permutation

// String is a sequence of characters. A permutation is a rearrangement of the characters in a string. The next permutation of a string is the next lexicographically greater permutation of its characters. For example, the next permutation of "abc" is "acb". The next permutation of "cba" is "abc". Given a string, find and print its next permutation. If it doesn't exist, print the lowest possible order (i.e., sorted in ascending order).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s){
    int i = n - 2;
    while (i >= 0 && strcmp(s[i], s[i + 1]) >= 0)
        i--;

    if (i < 0)
        return 0;

    int j = n - 1;
    while (strcmp(s[j], s[i]) <= 0)
        j--;

    char *temp = s[i];
    s[i] = s[j];
    s[j] = temp;

    int start = i + 1, end = n - 1;
    while (start < end)
    {
        char *t = s[start];
        s[start] = s[end];
        s[end] = t;
        start++;
        end--;
    }

    return 1;
}
