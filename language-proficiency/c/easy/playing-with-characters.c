#include <stdio.h>

int main(){
	char ch, str[250];
	scanf("%c\n", &ch);
	printf("%c\n", ch);
	
	/*
		1-scanf returns the number of inputs read i.e. the number of arguments that you 
		passed to 'fill'

		2-in this case if there is something to read it returns 1 i.e it reads to 'str'

		3-%[^\n] conversion specification that matches a string of all characters not equal 
		to '\n' and stores it in str

		4-%*c is basically indicating each char read by scanf (that is not '\n') is stored in
		a char pointer i.e each position of the string
	*/
	while(scanf("%[^\n]%*c", str) == 1){ 
		printf("%s\n",str);				
    }
}