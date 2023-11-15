/*
Experiment 3.1 - Recursive Descend Parser
Noel John Robert
B20CS1147

Grammar: S -> (L) | a
		 L -> SL'
		 L' -> ,SL' | ∈
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char look_ahead;
char* input_str;
int ind = 0;
int error = 0;

void S(), L(), Ldash();

char getNextToken() {
	return input_str[ind++];
}

void printParsingStep(char* _input, char* _action) {
	printf("%s\t\t\t%s\n", _input, _action);
}

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
		printParsingStep(input_str+ind, "matched");
		look_ahead = getNextToken();
	} else {
		printf("ERROR\n");
		error = 1;
	}
}

void S() {
	if (look_ahead == '(') {
		printParsingStep(input_str+ind, "S -> (L)");
		match('(');
		L();
		match(')');
	} else if (look_ahead == 'a') {
		printParsingStep(input_str+ind, "S -> a");
		match('a');
	} else {
		printf("ERROR\n");
		error = 1;
	}
}

void L() {
	printParsingStep(input_str+ind, "L -> SL'");
	S();
	Ldash();
}

void Ldash() {
	if (look_ahead == ',') {
		printParsingStep(input_str+ind, "L' -> ,SL'");
		match(',');
		S();
		Ldash();
	} else {
		printParsingStep(input_str+ind, "L' -> E");
	}
}

/*
OUTPUT
Input a string: (a,a)
a,a)$                   S -> (L)
a,a)$                   matched
,a)$                    L -> SL'
,a)$                    S -> a
,a)$                    matched
a)$                     L' -> ,SL'
a)$                     matched
)$                      S -> a
)$                      matched
$                       L' -> E
$                       matched
Parsing Successful
*/