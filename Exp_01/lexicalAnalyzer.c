#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char line[512];
int forwardPointer = 0;
int lexemeBegin = 0;

char* extract(char _line[256], int _lexemeBegin, int _forwardPointer) {
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

    while ((currentCharacter = _line[forwardPointer]) != '\0' && lexemeBegin < strlen(_line)) {
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
                    case 'i': ++forwardPointer; state = 1; break;    
                    case 'e': ++forwardPointer; state = 5; break;
                    case 'f': ++forwardPointer; state = 9; break;
                    case 'r': ++forwardPointer; state = 14; break;
                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'g':
                    case 'h':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'p':
                    case 'q':
                    case 's':
                    case 't':
                    case 'u':
                    case 'v':
                    case 'w':
                    case 'x':
                    case 'y':
                    case 'z': ++forwardPointer; state = 20; break;
                    case '<': ++forwardPointer; state = 21; break;
                    case '>': ++forwardPointer; state = 22; break;
                    case '=': ++forwardPointer; state = 23; break;
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9': ++forwardPointer; state = 24; break;
                    case '\n': ++forwardPointer; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;

            
            case 1:
                switch (currentCharacter) {
                    case 'n': ++forwardPointer; state = 2; break;
                    case 'f': ++forwardPointer; state = 4; break;
                    default: ++forwardPointer; state = 20; break;
                }
                break;
            case 2:
                switch (currentCharacter) {
                    case 't': ++forwardPointer; state = 3; break;
                    default: ++forwardPointer; state = 20; break;
                }
                break;
            case 3:
                switch (currentCharacter) {
                    case ' ': 
                    case '\n':
                    case ';': printf("accept(keyword, %s)\n", extract(_line, lexemeBegin, forwardPointer-1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: ++forwardPointer; state = 20; break; // continue checking coz identifier
                }
                break;

            case 4:
                switch (currentCharacter) {
                    case ' ': 
                    case '(': printf("accept(keyword, %s)\n", extract(_line, lexemeBegin, forwardPointer-1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: ++forwardPointer; state = 20; break; // continue checking coz identifier
                }
                break;
            
            case 5:
                switch (currentCharacter) {
                    case 'l': ++forwardPointer; state = 6; break;
                    default: ++forwardPointer; state = 20; break;
                }
                break;
            case 6:
                switch (currentCharacter) {
                    case 's': ++forwardPointer; state = 7; break;
                    default: ++forwardPointer; state = 20; break;
                }
                break;
            case 7:
                switch (currentCharacter) {
                    case 'e': ++forwardPointer; state = 8; break;
                    default: ++forwardPointer; state = 20; break;
                }
                break;
            case 8:
                switch (currentCharacter) {
                    case ' ': 
                    case '\n':
                    case '{': printf("accept(keyword, %s)\n", extract(_line, lexemeBegin, forwardPointer-1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: ++forwardPointer; state = 20; break; // continue checking coz identifier
                }
                break;

            case 9:
                switch (currentCharacter) {
                    case 'l': ++forwardPointer; state = 10; break;
                    default: ++forwardPointer; state = 20; break;
                }
                break;
            case 10:
                switch (currentCharacter) {
                    case 'o': ++forwardPointer; state = 11; break;
                    default: ++forwardPointer; state = 20; break;
                }
                break;
            case 11:
                switch (currentCharacter) {
                    case 'a': ++forwardPointer; state = 12; break;
                    default: ++forwardPointer; state = 20; break;
                }
                break;
            case 12:
                switch (currentCharacter) {
                    case 't': ++forwardPointer; state = 13; break;
                    default: ++forwardPointer; state = 20; break;
                }
                break;
            case 13:
                switch (currentCharacter) {
                    case ' ': 
                    case '\n':
                    case ';': printf("accept(keyword, %s)\n", extract(_line, lexemeBegin, forwardPointer-1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: ++forwardPointer; state = 20; break; // continue checking coz identifier
                }
                break;
            
            case 14:
                switch (currentCharacter) {
                    case 'e': ++forwardPointer; state = 15; break;
                    default: ++forwardPointer; state = 20; break;
                }
                break;
            case 15:
                switch (currentCharacter) {
                    case 't': ++forwardPointer; state = 16; break;
                    default: ++forwardPointer; state = 20; break;
                }
                break;
            case 16:
                switch (currentCharacter) {
                    case 'u': ++forwardPointer; state = 17; break;
                    default: ++forwardPointer; state = 20; break;
                }
                break;
            case 17:
                switch (currentCharacter) {
                    case 'r': ++forwardPointer; state = 18; break;
                    default: ++forwardPointer; state = 20; break;
                }
                break;
            case 18:
                switch (currentCharacter) {
                    case 'n': ++forwardPointer; state = 19; break;
                    default: ++forwardPointer; state = 20; break;
                }
                break;
            case 19:
                switch (currentCharacter) {
                    case ' ': 
                    case ';': printf("accept(keyword, %s)\n", extract(_line, lexemeBegin, forwardPointer-1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: // continue checking coz identifier
                }
                break;

            case 20: // checking for identifiers
                switch (currentCharacter) {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'e':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'i':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'p':
                    case 'q':
                    case 'r':
                    case 's':
                    case 't':
                    case 'u':
                    case 'v':
                    case 'w':
                    case 'x':
                    case 'y':
                    case 'z': ++forwardPointer; state = 20; break;
                    case ' ':
                    case ';' : printf("accept(identifier, %s)\n", extract(_line, lexemeBegin, forwardPointer-1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;

            case 21:
                switch (currentCharacter) {
                    case '>': printf("accept(relop, %s)\n", extract(_line, lexemeBegin, forwardPointer)); lexemeBegin = ++forwardPointer; state = 0; break;
                    case '=': printf("accept(relop, %s)\n", extract(_line, lexemeBegin, forwardPointer)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: printf("accept(relop, %s)\n", extract(_line, lexemeBegin, forwardPointer-1)); lexemeBegin = ++forwardPointer; state = 0; break;
                }
                break;
                
            case 22:
                switch (currentCharacter) {
                    case '=': printf("accept(relop, %s)\n", extract(_line, lexemeBegin, forwardPointer)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: printf("accept(relop, %s)\n", extract(_line, lexemeBegin, forwardPointer-1)); lexemeBegin = ++forwardPointer; state = 0; break;
                }            
                break;

            case 23:
                switch (currentCharacter) {
                    case '=': printf("accept(relop, %s)\n", extract(_line, lexemeBegin, forwardPointer)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: printf("accept(arithmetic, %s)\n", extract(_line, lexemeBegin, forwardPointer-1)); lexemeBegin = ++forwardPointer; state = 0; break;
                }
                break;

            case 24:
                switch (currentCharacter) {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9': ++forwardPointer; state = 24; break;
                    case ' ':
                    case ')':
                    case '}':
                    case '\n':
                    case ';' : printf("accept(number, %s)\n", extract(_line, lexemeBegin, forwardPointer-1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;


            default : printf("Unknown characer found - %c", currentCharacter); return; 
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
// keywords[if, int, else,  float, return], identifiers, numbers, relops
// currently handles if and else keywords, need newline symbol to recognize each
// 'if else ' is also being recognized properly
// check other states, might be missing a few in berween (3 and 4 ig ~ chat stoopid)