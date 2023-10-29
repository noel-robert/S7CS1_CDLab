/*
Recursive Descend Parser
Grammar: S -> (L) | a
         L -> SL'
         L' -> ,SL' | ∈
*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// char input[100];
// char *ip;
// // int index;

// int S(), L(), Ldash();

// // char* substr(int _ind) {
// //     char *res;
// // }

// int main() {
//     printf("input a string: ");
//     scanf("%s", input);
//     ip = input;

//     if (S()) {
//         printf("Successfully parsed the input string\n\n");
//     } else {
//         printf("Input string not parsed\n\n");
//     }

//     return 1;
// }

// int S() {
//     if (*ip == '(') {
//         printf("%s\t\t\tS -> (L)\n", ip);
//         ++ip;

//         if (L()) {
//             if (*ip == ')') {
//                 ++ip;
//                 return 1;
//             } else {
//                 return 0;
//             }
//         } else {
//             return 0;
//         }
//     } else if (*ip == 'a') {
//         ++ip;
//         printf("%s\t\t\tS -> a\n", ip);      
//         return 1;
//     } else {
//         return 0;
//     }
// }

// int L() {
//     printf("%s\t\t\tL -> SL'\n", ip);
//     if (S()) {
//         if (Ldash()) return 1;
//         else return 0;
//     } else {
//         return 0;
//     }
// }

// int Ldash() {
//     if (*ip == ',') {
//         printf("%s\t\t\tL' -> ,SL'\n", ip);
//         ++ip;

//         if (S()) {
//             if (Ldash()) return 1;
//             else return 0;
//         } else {
//             return 0;
//         }
//     } else {
//         printf("%s\t\t\tL' -> ∈\n", ip);
//         return 1;
//     }
// }



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char look_ahead;
char *input_str;
int ind = -1;

void E(), Edash();

char getNextToken() {
    return input_str[++ind];
}

void printParsingStep(char* _input, char* _action) {
    printf("%s\t\t\t%s\n", _input, _action);
}

int main () {
    // input string
    char inp[100];
    printf("Input a string: "); scanf("%s", inp);

    // append $ to input
    input_str = malloc(sizeof(char) * strlen(inp + 1));
    int i;
    for (i=0; i < strlen(inp); i++) input_str[i] = inp[i];
    input_str[i] = '$';

    look_ahead = getNextToken();

    E();
    if (look_ahead == '$') printf("Parsing successful\n");
    else printf("Parsing un-successful\n");

    return 0;
}

void match(char c) {
    if (look_ahead == c) {
        printParsingStep(input_str+ind, "Matched");
        look_ahead = getNextToken();
    }
    else {
        printf("Error\n");
        return;
    }
}

void E() {
    if (look_ahead == 'i') {
        printParsingStep(input_str+ind, "E -> iE'");
        match(look_ahead);
        Edash();
    }
}

void Edash() {
    if (look_ahead == '+') {
        printParsingStep(input_str+ind, "E -> +iE'");
        match('+');
        match('i');
        Edash();
    } else {
        printParsingStep(input_str+ind, "E -> ∈");
    }
}