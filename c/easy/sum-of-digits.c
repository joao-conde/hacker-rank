#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);

	while(n >= 1){
		sum += (n % 10);
		n /= 10;
	}
	printf("%d\n", sum);
}