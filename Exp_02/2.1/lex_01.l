/*
Experiment 2.1 - Lexical Analyzer for C programs using LEX
Noel John Robert
B20CS1147
*/


%{
    #include <stdio.h>    
%}

%%
if |
else |
int |
float |
return |
break |
continue |
printf |
char { printf("keyword %s\n", yytext); }
[a-zA-Z][a-zA-Z0-9]* { printf("identifier %s\n", yytext); }
["][a-zA-Z ]+["] |
['][a-zA-Z ]+['] { printf("literal %s\n", yytext); }
[+] |
[-] |
[*] |
[/] |
[=] { printf("operator %s\n", yytext); }
[0-9]+ |
[-][0-9]+ { printf("number %s", yytext); }
. { /*do nothing*/ }
%%

int main() {
    yyin = fopen("inputFile1.txt", "r");
    yylex();
    return 0;
}


/*
OUTPUT
identifier include
identifier stdio
identifier h

keyword int
identifier main

keyword int
identifier a
operator =
number 9
keyword float
identifier Bg
operator =
number -3
keyword if
identifier a
identifier b

keyword printf
literal "greater"

keyword else

keyword printf
literal "lesser"
*/