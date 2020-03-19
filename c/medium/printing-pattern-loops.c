#include <stdio.h>

int main(){
	int n, matrixSize;
	scanf("%d", &n);
	matrixSize = 2 * n - 1;

	//print matrix
	for(int i = 0; i < matrixSize; i++){
		for(int j = 0; j < matrixSize; j++){
			int min = (i < j ? i : j);
			min = (min < matrixSize - i ? min : matrixSize - i - 1);
            min = (min < matrixSize - j - 1 ? min : matrixSize - j - 1);
			printf("%d ", n - min);
		}
		printf("\n");
	}
}