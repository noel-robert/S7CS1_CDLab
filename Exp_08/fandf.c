/*
Experiment 08 - First and Follow
Noel John Robert
B20CS1147
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int prodCount = 0;
struct Productions {
    char left;
    char right[30];

	char first[100];
	int first_index;
	char follow[100];
	int follow_index;
} grammar[20];

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

int isTerminal(char symbol) {
	return islower(symbol);
}

void addToSet(char set[], char symbol, int *index) {
	for (int i=0; i<*index; i++) {
		if (set[i] == symbol) {
			return;	// symbol already exists
		}
	}

	set[(*index)++] = symbol;
}

void findFirst(char symbol) {
	/*
	Issue here:
	- two productions with same LHS means two different arrays for first and follow, along with symbol
	- so, first and follow should be another struct 
	*/
	for (int i=0; i<prodCount; i++) {
		if (grammar[i].left == symbol) {
			char firstSymbol = grammar[i].right[0];

			if (isTerminal(firstSymbol)) {
				addToSet(grammar[i].first, firstSymbol, &grammar[i].first_index);
			} else {
				if (firstSymbol != '#' && firstSymbol != '\0') {
					findFirst(firstSymbol);
				} else if (firstSymbol == '#') {
					addToSet(grammar[i].first, '#', &grammar[i].first_index);
				}
			}
		}
	}
}

void findFollow(char symbol) {}

int main() {
    FILE *inputFile = fopen("input.txt", "r");

    char line[30];
	int lineLen = 0;
	char ch;

    // copy production rules to structure
	while ((ch = getc(inputFile)) != EOF) {
		if (ch == '\n') {
			grammar[prodCount].left = line[0];
			strcpy(grammar[prodCount].right, extract(line, 3, lineLen-1));

			grammar[prodCount].first_index = 0;
			grammar[prodCount].follow_index = 0;
			prodCount++;

			lineLen = 0;
			continue;
		}

		line[lineLen++] = ch;
	}
	if (lineLen > 0) {
		grammar[prodCount].left = line[0];
		strcpy(grammar[prodCount].right, extract(line, 3, lineLen-1));

		grammar[prodCount].first_index = 0;
		grammar[prodCount].follow_index = 0;
		prodCount++;
	}



	// find first for every LHS of productions
	for (int i=0; i<prodCount; i++) {
		findFirst(grammar[i].left);
	}

	// find follow for every LHS of productions
	// for (int i=0; i<prodCount; i++) {
	// 	findFollow(grammar[i].left);
	// }


	for (int i=0; i<prodCount; i++) {
		printf("First(%c): %s\n", grammar[i].left, grammar[i].first);
		// printf("Follow(%c): %s\n", grammar[i].left, grammar[i].follow);
		printf("\n");
	}

	return 0;
}



/*
Note:
- # means epsilon
*/