#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char line[512];
int forwardPointer = 0;
int lexemeBegin = 0;

char* extractSubstring(char _line[256], int _lexemeBegin, int _forwardPointer) {
    char *result;
    int _length = _forwardPointer - _lexemeBegin;
    result = malloc((_length + 1) * sizeof(char));

    int _pos = 0;
    while (_pos < _length) {
        result[_pos] = _line[_lexemeBegin + _pos];
        _pos++;
    }
    result[_pos] = '\0';

    return result;
}

void deterministicFiniteAutomata(char _line[256]) {
    int state = 0;  // to store current state of the DFA

    int index = 0;
    lexemeBegin = forwardPointer = index;
    char currentCharacter;

    while ((currentCharacter = _line[forwardPointer]) != '\0') {
        // whitespace, so move forward
        // if (currentCharacter == ' ') {
        //     forwardPointer = lexemeBegin = index + 1;
        //     state = 0;
        //     continue;
        // }

        // states of the DFA
        // keywords[if, else, return, switch, break, continue], identifiers, numbers, relops

        switch(state) {
            case 0: 
                    switch(currentCharacter) {
                        case 'i': forwardPointer++; state = 1; break;
                        case 'f': forwardPointer++; state = -12345; break;
                        case 's': forwardPointer++; state = -12345; break;
                        case '+': break;
                        case '-': break;
                        case '*': break;
                        case '/': break;
                        case ' ': forwardPointer++; state = 0; break;
                        default : printf("Unknown characer found 1 - %c", currentCharacter); //return;
                    }
                    break;

            case 1: 
                    switch (currentCharacter) {
                        case 'n': forwardPointer++; state = 2; break;
                        default : printf("Unknown characer found 2 - %c", currentCharacter); //return;
                    }
                    break;

            case 2: 
                    switch (currentCharacter) {
                        case 't': forwardPointer++; state = 3; break;
                        default : printf("Unknown characer found 3 - %c", currentCharacter); //return;
                    }
                    break;

            case 3: 
                    switch (currentCharacter) {
                        case ';':
                        case ' ': printf("return(keyword, %s)\n", extractSubstring(_line, lexemeBegin, forwardPointer)); lexemeBegin = ++forwardPointer; state = 0; break;
                        case '\n': lexemeBegin = ++forwardPointer; state = 0; break;
                        default: // work
                    }
                    break;

            default : printf("Unknown characer found 4 - %c", currentCharacter); return; 
        }
    }

}

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