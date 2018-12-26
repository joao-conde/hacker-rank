/*
	Poorly written tutorial, no need to be an array when we could store current sum, let alone a dynamic one....
	but oh well
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int ints, sum = 0;
	scanf("%d", &ints);
	
	int* intArr = (int*) malloc(ints * sizeof(int));

	for(int i = 0; i < ints; i++){
		int n;
		scanf("%d", &n);
		*(intArr + i) = n;
	}

	for(int i = 0; i < ints; i++){
		sum += *(intArr + i);
	}

	printf("%d", sum);
}