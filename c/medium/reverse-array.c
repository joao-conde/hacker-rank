#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    
	for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

	int middle = num / 2;
	for(i = 0; i < middle; i++){
		int tmp = arr[i];
		arr[i] = arr[num-1-i];
		arr[num-1-i] = tmp;
	}

    for(i = 0; i < num; i++) printf("%d ", *(arr + i));
}