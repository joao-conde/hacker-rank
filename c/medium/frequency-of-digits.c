#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int freq[10]; //0..9
	memset(freq, 0, sizeof(freq));

	char *s = malloc(1001 * sizeof(char));
    scanf("%[^\n]", s);

	int strLen = strlen(s);
	for(int i = 0; i < strLen; i++){
		int digit = *(s + i) - '0';
		if(digit >= 0 && digit < 10) freq[digit]++;
	}

	for(int i = 0; i < 10; i++){
		printf("%d ", freq[i]);
	}
}
