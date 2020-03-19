#include <stdio.h>
#include <stdlib.h>

void update(int *a, int *b) {
	int aval = *a,
		bval = *b;

	*a = aval + bval;
	*b = abs(aval - bval);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);
}