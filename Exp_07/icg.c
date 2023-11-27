/*
Experiment 07 - Intermediate Code Generator
Noel John Robert
B20CS1147
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// struct to hold 3-address intermediate codes
struct addr {
	char left;
	char right[4];
} op[50];
int addr_ind = 0;

int stk_top = -1;	// points to top element
char stk[100];
void push(char ch) {
	stk[++stk_top] = ch;
}
char pop() {
	return stk[stk_top--];
}
int priority(char ch) {
	switch (ch) {
		case '$': return -2;

		case '(': return 1;

		case '+':
		case '-': return 2;

		case '*':
		case '/': return 3;
	}
}
char result[100];
void postfix(char input[100]) {
	int res_ind = 0;

	push('(');

	int i = 0;
	while (i < strlen(input)) {
		char ch = input[i++];

		// directly push to stack
		if (ch == '(' || ch == '^') {
			push(ch);
			continue;
		} 
		
		// if alphabet, add to result
		if (isalpha(ch)) {
			result[res_ind++] = ch;
			continue;
		} 
		
		// if ')' pop till '(' is found, then pop '('
		if (ch == ')') {
			while (stk[stk_top] != '(') {
				result[res_ind] = pop();
			}
			pop();
			continue;
		} 
		
		// push/pop based on priority
		while (priority(stk[stk_top]) >= priority(ch)) {
			result[res_ind++] = pop();
		}
		push(ch);
		
	}

	// remove remaining characters from stack
	while(stk_top != -1 && stk[stk_top] != '(') {
		result[res_ind++] = pop();
	}

	// add ending character to string
	result[res_ind] = '\0';
}


int main() {
	char input[100];
	printf("Input Expression: "); scanf("%s", input);
	
	char pfx[100];
	postfix(input);
	strcpy(pfx, result);
	printf("Equivalent postfix Expression: %s\n\n", pfx);
	
	
	int index = 0;
	char tempVar = 'A';
	char ch;
	int len = strlen(pfx);
	
	while (index < len) {
		ch = pfx[index];

		if (!isalpha(ch)) {
			// add data to struct
			op[addr_ind].left = tempVar;
			op[addr_ind].right[0] = pfx[index-2]; 
			op[addr_ind].right[1] = pfx[index];
			op[addr_ind].right[2] = pfx[index-1];
			op[addr_ind].right[3] = '\0';
			addr_ind++;
			
			// replace by temporary variable
			pfx[index-2] = tempVar;
			tempVar++;
			
			// left shift by 2
			for (int i=index+1; i<len; i++) {
				pfx[i-2] = pfx[i];
			}
			len = len - 2;
			index = 0;
			continue;
		} else {
			index++;
		}
	}
	
	printf("Intermediate 3 address codes:\n");
	for (int i=0; i<addr_ind; i++) {
		printf("%c = %s\n", op[i].left, op[i].right);
	}
	
	
	return 0;
}


/*
OUTPUT
Input Expression: a+b/c*d+e
Equivalent postfix Expression: abc/d*+e+

Intermediate 3 address codes:
A = b/c
B = A*d
C = a+B
D = C+e
*/

/*
Algorithm:
1. Take input expression from user
2. Convert input to postfix form pfx
3. Scan from Left to Right
3.1. on encountering operator, take that along with previous two operands to make new variable tx
3.2. pass if operand after incrementing index
*/