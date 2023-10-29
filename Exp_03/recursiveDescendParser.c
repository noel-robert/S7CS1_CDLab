/*
Recursive Descend Parser
Grammar: S -> (L) | a
         L -> SL'
         L' -> ,SL' | ∈
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char look_ahead;
char *input_str;
// int ind = -1;
int ind = 0;
int error = 0;

void S(), L(), Ldash();

char getNextToken() {
    // return input_str[++ind];
    return input_str[ind++];
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

    S();
    if (look_ahead == '$' && error == 0) printf("Parsing successful\n");
    else printf("Parsing un-successful\n");

    return 0;
}

void match(char c) {
    if (look_ahead == c) {
        // printParsingStep(input_str+ind, "Matched");
        look_ahead = getNextToken();
    } else {
        printf("Error M\n");
        error = 1;
        return;
    }
}

void S() {
    if (look_ahead == '(') {
        printParsingStep(input_str+ind, "S -> (L)");
        match('(');
        L();
        match(')');
        // return 1;
    } else if (look_ahead == 'a') {
        printParsingStep(input_str+ind, "S -> a");
        match('a');
        // return 1;
    } else {
        printf("Error S\n");
        error = 1;
        // exit(0);
    }
}

void L() {
    printParsingStep(input_str+ind, "L -> SL'");
    S();
    Ldash();
}
// void L() {
//     if (look_ahead == '(' || look_ahead == 'a') {
//         printParsingStep(input_str + ind, "L -> SL'");
//         S();
//         Ldash();
//     } else {
//         printf("Error L\n");
//         error = 1;
//     }
// }

void Ldash() {
    if (look_ahead == ',') {
        printParsingStep(input_str+ind, "L' -> ,SL'");
        match(',');
        S();
        Ldash();
    // } else if (look_ahead == '$') {
    //     printParsingStep(input_str+ind, "L' -> ∈");
    } else {
        // printf("Error L'\n");
        // error = 1;
        printParsingStep(input_str+ind, "L' -> ∈");
        // exit(0);
    }
}