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
} grammar[50];

int indexFF = 0;
struct FirstFollow {
	char left;

	char first[100];
	int first_index;

	char follow[100];
	int follow_index;
} symbolData[50];

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

int getIndexOfSymbol(char symbol) {
	for (int i=0; i<indexFF; i++) {
		if (symbolData[i].left == symbol) return i;
	}
	printf("Fatal Error\n\n");
	return -1;
}

void findFirst(char symbol, int index) {
	for (int i=0; i<prodCount; i++) {
		if (grammar[i].left == symbol) {
			char firstSymbol = grammar[i].right[0];

			if (isTerminal(firstSymbol)) {
				addToSet(symbolData[index].first, firstSymbol, &symbolData[index].first_index);
			} else {
				if (firstSymbol != '#' && firstSymbol != '\0') {
					findFirst(firstSymbol, getIndexOfSymbol(firstSymbol));
				} else if (firstSymbol == '#') {
					addToSet(symbolData[index].first, '#', &symbolData[index].first_index);
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
	do {
		ch = getc(inputFile);

		if (ch == '\n' || ch == EOF) {
			if (lineLen > 0) {
				grammar[prodCount].left = line[0];
				strcpy(grammar[prodCount].right, extract(line, 3, lineLen-1));
				prodCount++;

				lineLen = 0;
			}
		} else {
			line[lineLen++] = ch;
		}
	} while (ch != EOF);


	// iterate through each left in grammar[]. add to symbolData[] if not present in it 
	for(int i=0; i<prodCount; i++) {
		char ch = grammar[i].left;

		// check if ch already in symbolData[]
		int found = 0;
		for (int j=0; j<indexFF; j++) {
			if (symbolData[j].left == ch) {
				found = 1;
				break;
			}
		}
		if (found == 0) {
			symbolData[indexFF].left = ch;
			symbolData[indexFF].first_index = 0;
			symbolData[indexFF].follow_index = 0;
			indexFF++;
		}
	}

	// find first for every LHS of productions
	for (int i=0; i<indexFF; i++) {
		findFirst(symbolData[i].left, i);
	}

	// find follow for every LHS of productions
	// for (int i=0; i<indexFF; i++) {
	// 	findFollow(symbolData[i].left);
	// }


	for (int i=0; i<indexFF; i++) {
		// printf("First(%c): %s\n", symbolData[i].left, symbolData[i].first);
		printf("First(%c): { %c", symbolData[i].left, symbolData[i].first[0]);
		if (strlen(symbolData[i].first) > 1) {
			for (int j=1; j<strlen(symbolData[i].first); j++) printf(", %c", symbolData[i].first[j]);
		}
		printf(" }\n");
	}

	return 0;
}



/*
Note:
- # means epsilon
*/