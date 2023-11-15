/*
Experiment 2.2 - Number of words from a set of strings
Noel John Robert
B20CS1147
*/


%{
    #include <stdio.h>
    int count = 0;
%}

%%
[a-zA-Z0-9]* { count++; }
. { /*do nothing*/ }
%%

int main() {
    yyin = fopen("inputFile2.txt", "r");
    yylex();
    printf("Words = %d\n", count);
    return 0;
}


/*
OUTPUT
Words = 6
*/