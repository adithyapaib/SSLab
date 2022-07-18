%{
#include<stdio.h>
#include<stdlib.h>
%}

%token NUM OP CP EOL
%left '+' '-'
%left '*' '/'

%%

stmt: exp EOL {printf("result = %d\n",$1); exit(0);}
exp: exp '+' exp{$$=$1+$3;}
|exp '-' exp{$$=$1-$3;}
|exp '*' exp{$$=$1*$3;}
|exp '/' exp{if($3==0){
printf("divide by zero error");
exit(0);
}
$$=$1/$3;
}
|OP exp CP {$$=$2;}
|NUM {$$=$1;};
%%
main()
{
printf("enter the expression ");
yyparse();
}
yyerror(){
printf("invalid input\n");
exit(0);
}
yywrap(){
}
