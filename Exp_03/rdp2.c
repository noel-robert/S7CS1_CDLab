/*
Experiment 3.2 - Recursive Descend Parser
Noel John Robert
B20CS1147

Grammar: S -> aaAB
		 A -> aaA | ∈
		 B -> bB | ∈
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char look_ahead;
char* input_str;
int ind = 0;
int error = 0;

void S(), A(), B();

char getNextToken() {
	return input_str[ind++];
}
/*
void printParsingStep(char* _input, char* _action) {
	printf("%s\t\t\t%s\n", _input, _action);
}
*/
int main() {
	char inp[100];
	printf("Input a string: "); scanf("%s", inp);
	
	input_str = malloc(sizeof(char) * (strlen(inp) + 1));
	int i = 0;
	while (i<strlen(inp)) {
		input_str[i] = inp[i];
		i++;
	}
	input_str[i] = '$';
	
	look_ahead = getNextToken();
	
	S();
	if (look_ahead == '$' && error == 0) printf("Parsing Successful\n");
	else printf("Parsing un-successful\n");
	
	return 0;
}

void match(char c) {
	if (look_ahead == c) {
		// printParsingStep(input_str+ind, "matched");
		look_ahead = getNextToken();
	} else {
		printf("ERROR\n");
		error = 1;
	}
}

void S() {
	if (look_ahead == 'a') {
		// printParsingStep(input_str+ind, "S -> aaAB");
		match('a');
		
		if (look_ahead == 'a') {
			// printParsingStep(input_str+ind, "S -> aaAB");
			match('a');
			A();
			B();
		} else {
			printf("ERROR\n");
			error = 1;
		}
		
		/*
		match('a');
		A();
		B();
		*/
	} else {
		printf("ERROR\n");
		error = 1;
	}
}

void A() {
	if (look_ahead == 'a') {
		// printParsingStep(input_str+ind, "A -> aaA");
		match('a');
		
		if (look_ahead == 'a') {
			// printParsingStep(input_str+ind, "A -> aaA");
			match('a');
			A();
		} else {
			printf("ERROR\n");
			error = 1;
		}
		
		/*
		match('a');
		A();
		B();
		*/
	} else if (look_ahead == '$') {
		// printParsingStep(input_str+ind, "A -> E");
	}
}

void B() {
	if (look_ahead == 'b') {
		// printParsingStep(input_str+ind, "B -> bB");
		match('b');
		
		B();
	} else if (look_ahead == '$') {
		// printParsingStep(input_str+ind, "B -> E");
	}
}

/*
OUTPUT
Input a string: aaaabb
Parsing Successful
*/

/*
OUTPUT
Input a string: aaabb
ERROR
Parsing un-successful
*/