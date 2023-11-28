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

	char first[30];
	int first_index;
	char follow[30];
	int follow_index;
} grammar[20];


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





}



/*
Note:
- # means epsilon
*/