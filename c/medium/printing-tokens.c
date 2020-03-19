#include <stdio.h>
#include <stdlib.h>

int main() {
    char *s = malloc(15 * sizeof(char));
    scanf("%[^\n]", s);

	int i = 0;
	while(*(s + i) != '\0'){
		char c = *(s + i);
		if(c == ' ')
			printf("\n");
		else
			printf("%c", c);
		i++;
	}
}