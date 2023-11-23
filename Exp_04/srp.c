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
	printf("pushed - %c\n", ch);
	stk[stk_top++] = ch;
}
char pop() {
	printf("removing - %c\n", stk[--stk_top]);
	return stk[stk_top];
}

// shift and reduce operations
void shift(char input) {
	push(input);

	// debug
	printf("%d::", stk_top);
	for (int i=0; i<stk_top; i++) {
		printf("%c", stk[i]); 
	}
	printf("\n\n");
}
void reduce(int productionIndex) {
	for (int i=0; i<strlen(grammar[productionIndex].right); i++) {
		pop();
	}

	push(grammar[productionIndex].left);

	// debug
	printf("%s\n\n", stk);
}

int main() {

	FILE *inputFile = fopen("grammar.txt", "r");
	
	char line[30];
	int lineLen = 0;
	char ch;

	while ((ch = getc(inputFile)) != EOF) {
		if (ch == '\n') {
			grammar[prodCount].left = line[0];
			strcpy(grammar[prodCount].right, extract(line, 3, lineLen-1));
			prodCount++;

			lineLen = 0;
			continue;
		}

		line[lineLen++] = ch;
	}
	if (lineLen > 0) {
		grammar[prodCount].left = line[0];
		strcpy(grammar[prodCount].right, extract(line, 3, lineLen-1));
		prodCount++;
	}

	
	// input string
	char str[100];
	printf("\nInput string: "); scanf("%s", str);
	strcpy(str, appendDollarSymbol(str));
	int str_index = 0;	// to track position in str

	// debug
	// printf("%s\n", str);
	// printf("%d\n\n", strlen(str));
	
	// processes
	push('$');

	while (1) {
		ch = str[str_index];

		// exit condition
		// exit condition is wrong
		if ((stk[stk_top-2] == '$') && (stk[stk_top-1] == grammar[0].left) && (ch == '$')) {
			printf("Successfully parsed string using given grammar\n");
			break;
		}

		/*
		when does parsing not work? - failure
		- reached end of string, so nly reduction is possible but cannot reduce
		*/
		

		if (stk[stk_top-1] == '$') {
			// initial condition
			shift(ch);
			str_index++; // only do str_index++ on shifting
			continue;
		}

		/*
		check if reduction can be done on elements in stack
		count no of possible reductions - 
		- if zero, try shifting
		- if one, reduce
		- if > 1, reduce reduce conflict
		*/
		int possible_reductions = 0;
		int reduction = -1;
		for (int i=0; i<prodCount; i++) {
			int len = strlen(grammar[i].right);

			if ((stk_top-1 >= len) && (strcmp(extract(stk, stk_top-len, stk_top-1), grammar[i].right) == 0)) {
				// reduction is possible
				possible_reductions++;
				reduction = i;
				// also count no of possible reductions to find reduce-reduce conflict
			}
		}

		if (possible_reductions == 0) {
			if (ch == '$') {
				printf("Not possible to Parse string using given grammar\n");
				break;
			}

			shift(ch);
			str_index++;
			continue;
		} else if (possible_reductions == 1) {
			printf("Using grammar: %c->%s\n", grammar[reduction].left, grammar[reduction].right);
			reduce(reduction);
		} else {
			printf("Reduce-Reduce conflict occurred\n");
			break;
		}
	}



	// printf("%s\n", stk);














	// some problem here, check condition individually
	// if (stk[stk_top - 1] == '$' && stk_top == 1 && str[str_index] == '$') {
	// 	printf("Parsing successful\n");
	// } else {
	// 	printf("Parsing unsuccessful\n");
	// }
	

	// debugging
	// if (!(stk[stk_top - 1] == '$')) {
	// 	printf("stk[stk_top - 1] == '$'\n");
	// } else if (!(stk_top == 1)) {
	// 	printf("stk_top == 1\n");
	// } else if (!(str[str_index] == '$')) {
	// 	printf("%c\n", str[str_index]);
	// } else {
	// 	printf("Dunnno bruv\n");
	// }

	// debug
	// for (int i = 0; i < prodCount; i++) {
    // 	printf("Production %d: %c -> %s\n", i + 1, grammar[i].left, grammar[i].right);
	// }
	

	return 0;
}



// int main() {
// 	char str[30] = "abcdefghij";

// 	printf("%s", extract(str, 2, 4)); /* cde */
// 	return 0;
// }


/*
OUTPUT

*/