#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct SymbolTable {
    int id;
    char *identifier;
} symtab[25];

int forwardPointer = 0;
int lexemeBegin = 0;
int symtab_index = 0;

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

    lexemeBegin = forwardPointer = 0;
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
                    case 'i': ++forwardPointer; state = 1; break;   // for recognizing keywords - if, int
                    case 'e': ++forwardPointer; state = 5; break;   // for recognizing keyword - else
                    case 'f': ++forwardPointer; state = 9; break;   // for recognizing keyword - float
                    case 'r': ++forwardPointer; state = 14; break;   // for recognizing keyword - return
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
                    case 'z': ++forwardPointer; state = 20; break;  // for recognizing identifiers that dont start with [e, f, i, r]
                    case '<': ++forwardPointer; state = 21; break;  // to reconize relational operators - <>, <=, <
                    case '>': ++forwardPointer; state = 22; break;  // to reconize relational operators - >=, >
                    case '=': ++forwardPointer; state = 23; break;  // to reconize relational operator == and assignment operator =
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9': ++forwardPointer; state = 24; break;  // to recognize numbers
                    case '\n': ++forwardPointer; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;

            // recognizing 'if' and 'int' keywords
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
                    default: ++forwardPointer; state = 20; break; // continue checking for identifier
                }
                break;
            case 4:
                switch (currentCharacter) {
                    case ' ': 
                    case '(': printf("accept(keyword, %s)\n", extract(_line, lexemeBegin, forwardPointer-1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: ++forwardPointer; state = 20; break; // continue checking for identifier
                }
                break;
            
            // recognizing 'else' keyword
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
                    default: ++forwardPointer; state = 20; break; // continue checking for identifier
                }
                break;

            // recognizing 'float' keyword
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
                    default: ++forwardPointer; state = 20; break; // continue checking for identifier
                }
                break;
            
            // recognizing 'return' keyword
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
                    default: ++forwardPointer; state = 20; break; // continue checking for identifier
                }
                break;

            // checking for identifiers
            case 20: 
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
                    case ';' : char *idf = extract(_line, lexemeBegin, forwardPointer-1);
                               symtab[symtab_index].id = symtab_index + 1; symtab[symtab_index].identifier = idf; ++symtab_index;
                               printf("accept(identifier, %s)\n", idf); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;

            // checking for relops '<>' and '<=' and '<'
            case 21:
                switch (currentCharacter) {
                    case '>': printf("accept(relop, %s)\n", extract(_line, lexemeBegin, forwardPointer)); lexemeBegin = ++forwardPointer; state = 0; break;
                    case '=': printf("accept(relop, %s)\n", extract(_line, lexemeBegin, forwardPointer)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: printf("accept(relop, %s)\n", extract(_line, lexemeBegin, forwardPointer-1)); lexemeBegin = ++forwardPointer; state = 0; break;
                }
                break;

            // checking for relops '>=' and '>'
            case 22:
                switch (currentCharacter) {
                    case '=': printf("accept(relop, %s)\n", extract(_line, lexemeBegin, forwardPointer)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: printf("accept(relop, %s)\n", extract(_line, lexemeBegin, forwardPointer-1)); lexemeBegin = ++forwardPointer; state = 0; break;
                }            
                break;

            // checking for relational operator '==' and assignment operator '='
            case 23:
                switch (currentCharacter) {
                    case '=': printf("accept(relop, %s)\n", extract(_line, lexemeBegin, forwardPointer)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: printf("accept(arithmetic, %s)\n", extract(_line, lexemeBegin, forwardPointer-1)); lexemeBegin = ++forwardPointer; state = 0; break;
                }
                break;

            // checking for numbers
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
                    case '.': ++forwardPointer; state = 25; break;
                    case ' ':
                    case ')':
                    case '}':
                    case '\n':
                    case ';' : printf("accept(number, %s)\n", extract(_line, lexemeBegin, forwardPointer-1)); lexemeBegin = ++forwardPointer; state = 0; break;
                    default: printf("Unknown character found - %c\n", currentCharacter); return;
                }
                break;
            case 25:
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
                    case '9': ++forwardPointer; state = 25; break;
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

    char line[512];

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        // you have each line individually in the variable named line
        if (line[0] == '#' || (line[0] == '/' && line[1] == '/')) continue; // skip if preprocessor directive or comment line
        else deterministicFiniteAutomata(line);
    }

    // show symtab contents
    int i = 0;
    printf("\nSymbolTable\nID\tIdentifier");
    while (i < symtab_index) {
        printf("\n%d\t%s", symtab[i].id, symtab[i].identifier);
        i++;
    }
    printf("\n\n");
    return 0;
}