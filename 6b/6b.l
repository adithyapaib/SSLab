%{
#include<stdio.h>
#include "y.tab.h"
extern yylval;
%}
%%
[\t] ;
[\+\-\*\/\<\=\>] {printf("operators is %s\n",yytext);return OP;}
[0-9]+ {yylval=atoi(yytext);printf("number is %\n",yylval;return DIGIT;}
int|char|bool|float|void|for|do|while|if|else|return|scanf|printf {printf("keyword is %s\n",yytext);return KEY;}
[a-zA-Z_][a-zA-Z_0-9]* {printf("identifier is %s\n",yytext);return ID;}
.;
%%


