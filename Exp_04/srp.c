/*
Experiment 4 - Shift Reduce Parser
Noel John Robert
B20CS1147
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Productions {
	char lhs[10];
	char rhs[30];
} gr[20];

int prodCount = 0;

int top = 0;
char stk[100];
void push(char ch) {
	stk[++top] = ch;
}
char pop() {
	return stk[top--];
}

int main() {
	// input grammar
	// input string
	
	printf("Input no of productions: "); scanf("%d", &prodCount);
	
	// input productions
	printf("Input productions[without any spaces]:\n");
	char inp[100];
	for (int i=0; i<prodCount; i++) {
		scanf("%s", inp);
		
		int index = 0;
		int j;
		for (j=0; j<strlen(inp); j++) {
			if(inp[j] == ' ' || inp[j] == '-') {
				// add to lhs \0, break
				gr[i].lhs[index] = '\0';
				break;
			}
			// add character to lhs
			gr[i].lhs[index] = inp[j];
			index++;
		}
		
		index = 0;
		for (; j<strlen(inp); j++) {
			if (inp[j] == ' ' || inp[j] == '>') {
				index++;
				continue;
			}
			gr[i].rhs[index] = inp[j];
			index++;
		}
		gr[i].rhs[index] = '\0';
	}
	
	char str[100];
	printf("Input string[append $ at end]: "); scanf("%s", str);
	
	
	
	// processes 
	push('$');
	
	// loop through str from l->r and check
	for (int i=0; i<strlen(str); i++) {
		// shift, reduce if possible
	}
	
	
	
	return 0;
}

/*
OUTPUT

*/