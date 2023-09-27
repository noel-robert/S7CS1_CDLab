#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char line[512];
int forwardPointer = 0;
int lexemeBegin = 0;

char* extractSubstring(char _line[256], int _lexemeBegin, int _forwardPointer) {
    char *result;
    int _length = _forwardPointer - _lexemeBegin + 1;
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
        switch(state) {
            case 0: 
                switch(currentCharacter) {
                    case 'i': forwardPointer++; state = 1; break;
                    case 'e': forwardPointer++; state = 5; break;
                    case 'r': forwardPointer++; state = 9; break;
                    case 's': forwardPointer++; state = 13; break;
                    case 'b': forwardPointer++; state = 17; break;
                    case 'c': forwardPointer++; state = 20; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;

            
            case 1:
                switch (currentCharacter) {
                    case 'f': forwardPointer++; state = 2; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 2:
                switch (currentCharacter) {
                    case ' ': printf("return(keyword, %s)\n", extractSubstring(_line, lexemeBegin, forwardPointer - 1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    case '\n': printf("return(keyword, %s)\n", extractSubstring(_line, lexemeBegin, forwardPointer - 1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: // continue checking
                }
                break;

            // Handle "else" keyword
            case 5:
                switch (currentCharacter) {
                    case 'l': forwardPointer++; state = 6; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 6:
                switch (currentCharacter) {
                    case 's': forwardPointer++; state = 7; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 7:
                switch (currentCharacter) {
                    case 'e': forwardPointer++; state = 8; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 8:
                switch (currentCharacter) {
                    case ' ': printf("return(keyword, %s)\n", extractSubstring(_line, lexemeBegin, forwardPointer - 1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    case '\n': printf("return(keyword, %s)\n", extractSubstring(_line, lexemeBegin, forwardPointer - 1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: // continue checking
                }
                break;

            // Handle "return" keyword
            case 9:
                switch (currentCharacter) {
                    case 'e': forwardPointer++; state = 10; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 10:
                switch (currentCharacter) {
                    case 't': forwardPointer++; state = 11; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 11:
                switch (currentCharacter) {
                    case 'u': forwardPointer++; state = 12; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 12:
                switch (currentCharacter) {
                    case 'r': forwardPointer++; state = 12; break;
                    case ' ': printf("return(keyword, %s)\n", extractSubstring(_line, lexemeBegin, forwardPointer - 1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    case '\n': printf("return(keyword, %s)\n", extractSubstring(_line, lexemeBegin, forwardPointer - 1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: // continue checking
                }
                break;

            // Handle "switch" keyword
            case 13:
                switch (currentCharacter) {
                    case 'w': forwardPointer++; state = 14; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 14:
                switch (currentCharacter) {
                    case 'i': forwardPointer++; state = 15; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 15:
                switch (currentCharacter) {
                    case 't': forwardPointer++; state = 16; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 16:
                switch (currentCharacter) {
                    case 'c': forwardPointer++; state = 16; break;
                    case ' ': printf("return(keyword, %s)\n", extractSubstring(_line, lexemeBegin, forwardPointer - 1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    case '\n': printf("return(keyword, %s)\n", extractSubstring(_line, lexemeBegin, forwardPointer - 1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: // continue checking
                }
                break;

            // Handle "break" keyword
            case 17:
                switch (currentCharacter) {
                    case 'r': forwardPointer++; state = 18; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 18:
                switch (currentCharacter) {
                    case 'e': forwardPointer++; state = 19; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 19:
                switch (currentCharacter) {
                    case 'a': forwardPointer++; state = 19; break;
                    case 'k': forwardPointer++; state = 19; break;
                    case ' ': printf("return(keyword, %s)\n", extractSubstring(_line, lexemeBegin, forwardPointer - 1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    case '\n': printf("return(keyword, %s)\n", extractSubstring(_line, lexemeBegin, forwardPointer - 1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: // continue checking
                }
                break;

            // Handle "continue" keyword
            case 20:
                switch (currentCharacter) {
                    case 'o': forwardPointer++; state = 21; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 21:
                switch (currentCharacter) {
                    case 'n': forwardPointer++; state = 22; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 22:
                switch (currentCharacter) {
                    case 't': forwardPointer++; state = 23; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 23:
                switch (currentCharacter) {
                    case 'i': forwardPointer++; state = 24; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 24:
                switch (currentCharacter) {
                    case 'n': forwardPointer++; state = 24; break;
                    case 'u': forwardPointer++; state = 24; break;
                    case 'e': forwardPointer++; state = 24; break;
                    case ' ': printf("return(keyword, %s)\n", extractSubstring(_line, lexemeBegin, forwardPointer - 1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    case '\n': printf("return(keyword, %s)\n", extractSubstring(_line, lexemeBegin, forwardPointer - 1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: // continue checking
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

// NOTE
// keywords[if, else, return, switch, break, continue], identifiers, numbers, relops
// currently handles if and else keywords, need newline symbol to recognize each
// 'if else ' is also being recognized properly
// check other states, might be missing a few in berween (3 and 4 ig ~ chat stoopid)