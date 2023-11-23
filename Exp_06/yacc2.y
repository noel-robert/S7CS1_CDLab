%{
#include <stdio.h>
%}
%token NUMBER
%left '+' '-'
%left '*' '/'
%left '%'
%right '^'
%%
E: T { printf("Result = %d\n", $$); return 0; }
T:  T '+' T { $$ = $1 + $3; }
	| T '-' T { $$ = $1 - $3; }
	| T '*' T { $$ = $1 * $3; }
	| T '/' T { $$ = $1 / $3; }
	| T '%' T { $$ = $1 % $3; }
	| T '^' T { 
					double prod = 1;
					for (int i=1; i<=$3; i++) prod = prod*$1;
					$$ = prod;
			  }
	| '-' NUMBER { $$ = -$2; }
	| '(' T ')' { $$ = $2; }
	| T '!' { 
				int fact = 1;
				for (int i=1; i<=$1; i++) fact = fact * i;
				$$ = fact; 
			}
	| NUMBER { $$ = $1; }
%%

int main() {
	printf("Enter the expression: ");
	yyparse();
}

int yyerror(char* s) {
	printf("\nExpression invalid\n");
}
