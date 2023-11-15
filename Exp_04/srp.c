/*
Experiment 4 - Shift Reduce Parser
Noel John Robert
B20CS1147
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* extract(char _input[30], int _start, int _end) {
    char *result;
    int _length = _end - _start + 1;
    result = malloc((_length + 1) * sizeof(char));

    int _pos = 0;
    while (_pos < _length) {
        result[_pos] = _input[_start + _pos];
        _pos++;
    }
    result[_pos] = '\0';

    return result;
}

char* appendDollarSymbol(char _input[30]) {
	char *result;
    int _length = strlen(_input);
    result = malloc((_length + 1) * sizeof(char));

	int i = 0;
	while (i<strlen(_input)) {
		result[i] = _input[i];
		i++;
	}
	result[i] = '$';

	return result;
}

// struct to hold grammar
int prodCount = 0;
struct Productions {
	char left;
	char right[30];
} grammar[20];

// stack operations
int stk_top = 0;
char stk[100];
void push(char ch) {
	stk[stk_top++] = ch;
}
char pop() {
	return stk[stk_top--];
}

int main() {
	printf("Input no of productions: "); scanf("%d", &prodCount);
	
	// input productions
	printf("\nInput productions[without any spaces, like A->...]:\n");
	char input[100];
	for (int i=0; i<prodCount; i++) {
		scanf("%s", input);
		
		grammar[i].left = input[0];
		strcpy(grammar[i].right, extract(input, 3, strlen(input)));
	}
	
	// input string
	char str[100];
	printf("Input string: "); scanf("%s", str);
	strcpy(str, appendDollarSymbol(str));
	int str_index = 0;	// to track position in str
	
	/*
	consider stk like a string; add new characters to right side; check from right to left;
	*/
	// processes 
	push('$');
	// first, push a $symbol to stk to indicate empty stack
	// is stk empty, or dont match, push element to stack, ie shift
	// check if stack top ie right-most element matches RHS of production else take right two elements nd check. continue this till $ found.
	while (stk[stk_top-1] != '$' && str[str_index] != '$') {

	}


	if (stk[stk_top-1] == '$' && stk_top == 1 && str[str_index] == '$')
		printf("Parsing successful");
	else 
		printf("Parsing unsuccessful");
	

	return 0;
}

/*
OUTPUT

*/