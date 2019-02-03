#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generation in lexicographic order from
// https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order

// Find the largest index k such that a[k] < a[k + 1].
// If no such index exists, the permutation is the last permutation.
int find_index_k(int n, char **s) {
    for (int i = n - 2; i >= 0; i--) {
        if (strcmp(*(s + i), *(s + i + 1)) < 0) return i;
    }
    return -1;
}

// Find the largest index l greater than k such that a[k] < a[l].
int find_index_l(int n, char **s, int k) {
    char *kstr = *(s + k);
    for (int i = n - 1; i > k; i--) {
        if (strcmp(kstr, *(s + i)) < 0) return i;
    }
    return -1;
}

// Swap the value of a[k] with that of a[l].
void swap(char **s, int k, int l) {
    char *tmp = *(s + k);
    *(s + k) = *(s + l);
    *(s + l) = tmp;
}

// Reverse the sequence from a[k + 1] up to and including the final element.
void reverseEnd(int n, char **s, int k) {
    int fPos = k + 1, lPos = n - 1;
    while (fPos <= lPos) {
        swap(s, fPos, lPos);
        fPos++;
        lPos--;
    }
}

int next_permutation(int n, char **s) {
    int k = find_index_k(n, s);
    if (k == -1) return 0;
    int l = find_index_l(n, s, k);
    swap(s, k, l);
    reverseEnd(n, s, k);
    return 1;
}

int main() {
    char **s;
    int n;
    scanf("%d", &n);

    s = calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++) {
        s[i] = calloc(11, sizeof(char));
        scanf("%s", s[i]);
    }

    do {
        for (int i = 0; i < n; i++)
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
    } while (next_permutation(n, s));

    for (int i = 0; i < n; i++) free(s[i]);

    free(s);

    return 0;
}