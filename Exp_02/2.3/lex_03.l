/*
Experiment 2.1 - Number of vovels in a string
Noel John Robert
B20CS1147
*/


%{
    #include <stdio.h>
    int count = 0;
%}

%%
a |
A |
e |
E |
i |
I |
o |
O |
u |
U { count++; }
. {  /*do nothing*/ }
%%

int main() {
    yyin = fopen("inputFile3.txt", "r");
    yylex();
    printf("Vovels = %d\n", count);
    return 0;
}


/*
OUTPUT
Vovels = 3
*/