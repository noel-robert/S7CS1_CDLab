%{
	/*Definition section*/
	#include "y.tab.h"
	extern yylval;
%}

%%
[0-9]+    {
			  yylval = atoi(yytext);
			  return NUMBER;
		  }
[ \t]+	; /* for skipping whitespace */
\n		  { return 0; }
.		  { return yytext[0]; }
%%
