#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double heronFormula(triangle* tri){
	double p = (tri->a + tri->b + tri->c) / 2.0;
	return sqrt(p * (p - tri->a) * (p - tri->b) * (p - tri->c));
}

int comp (const void * elem1, const void * elem2) {
	double area1 = heronFormula((triangle*)elem1), area2 = heronFormula((triangle*)elem2);
	return (area1 >= area2 ? 1 : -1);
}

void sort_by_area(triangle* tr, int n) {
	qsort(tr, n, sizeof(*tr), comp);
}

int main(){
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	
	sort_by_area(tr, n);

	for (int i = 0; i < n; i++) {
		printf("%d %d %d - area %f\n", tr[i].a, tr[i].b, tr[i].c, heronFormula(tr+i));
	}
}