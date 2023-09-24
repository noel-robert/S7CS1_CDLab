#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char line[512];
int forwardPointer = 0;
int lexemeBegin = 0;

// to extract parts - is this needed??
char* extractSubstring(char _line[256], int _lexemeBegin, int _forwardPointer) {
    char *value;
    int _length = _forwardPointer - _lexemeBegin + 1;
    value = malloc(_length * sizeof(char));

    int _pos = 0;
    while (_pos < _length) {
        value[_pos] = _line[_lexemeBegin + _pos];
        _pos++;
    }
    value[_pos] = '\0';

    return value;
}

// void deterministicFiniteAutomata(char line[256]) {
//     int forwardPointer = 0;
//     int lexemeBegin = 0;
//     // goto state_initial;

// state_initial:
//     if (line[forwardPointer] == 'i') {
//         forwardPointer++;
//         goto state1;
//     } else {}

// state1:
//     if (line[forwardPointer] == 'n') {
//         forwardPointer++;
//         goto state2;
//     } else {}

// state2:
//     if (line[forwardPointer] == 't') {
//         forwardPointer++;
//         goto state3;
//     } else {}

// state3:
//     if (!isalnum(line[forwardPointer])) {
//         forwardPointer--;
//         printf("return(keyword, %s)\n", extractSubstring(line, lexemeBegin, forwardPointer));
//         forwardPointer = lexemeBegin = forwardPointer + 2;
//         // goto state_initial;
//     } else {
//         forwardPointer++;
//         goto state_identifier;
//     }

// state_identifier:
//     if (isalnum(line[forwardPointer])) {
//         forwardPointer++;
//         goto state_identifier;
//     } else {
//         forwardPointer--;
//         printf("return(identifier, %s)\n", extractSubstring(line, lexemeBegin, forwardPointer));
//         // goto state_initial;
//     }
// }

void state0() {}

int main() {
    FILE *inputFile;
    inputFile = fopen("inputFile.txt", "r");

    // char line[512];

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        // you have each line individually in the variable named line
        if (line[0] == '#' || (line[0] == '/' && line[1] == '/')) continue; // skip if preprocessor directive or comment line
        else deterministicFiniteAutomata(line);
    }

    return 0;
}