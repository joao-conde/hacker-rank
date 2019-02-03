#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    return (strcmp(a, b) <= 0);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
	return (strcmp(a, b) >= 0);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
	int freqA[26], freqB[26]; //english lower-case alphabet
	memset(freqA, 0, sizeof(freqA));
	memset(freqB, 0, sizeof(freqB));
	
	for(const char* ita = a; *ita != '\0'; ita++){
		freqA[*ita - 'a']++; 
	}

	for(const char* itb = b; *itb != '\0'; itb++){
		freqB[*itb - 'a']++; 
	} 

	int distinctA = 0, distinctB = 0;
	for(int i = 0; i < 26; i++){
		if(freqA[i] > 0) distinctA++;
		if(freqB[i] > 0) distinctB++;
	}	

	if(distinctA == distinctB)
		return lexicographic_sort(a, b);
	else 
		return (distinctA < distinctB);
}

int sort_by_length(const char* a, const char* b) {
	int lenA = strlen(a), lenB = strlen(b);
	if(lenA == lenB)
		return lexicographic_sort(a, b);
	else
		return (lenA < lenB);
}

void string_sort(char** arr, const int len,
                 int (*cmp_func)(const char* a, const char* b)) {
    for (int j = 0; j < len; j++) {
        for (int i = 0; i < len - 1; i++) {
            if (!cmp_func(arr[i], arr[i + 1])) {
                char* temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char** arr;
    arr = (char**)malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for (int i = 0; i < n; i++) printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for (int i = 0; i < n; i++) printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for (int i = 0; i < n; i++) printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for (int i = 0; i < n; i++) printf("%s\n", arr[i]);
    printf("\n");
}