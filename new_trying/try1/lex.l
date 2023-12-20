%{
    #include <stdio.h>    
%}

%%
[a-zA-Z][a-zA-Z0-9._-]*@gmail.com { printf("Valid Email: %s\n", yytext); }
. ;
%%

int main() {
    yyin = fopen("input.txt", "r");
    yylex();
    return 0;
}