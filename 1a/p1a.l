%{
#include<stdio.h>
int id=0,op=0,flag=0,v=0;
%}

%%
[0-9]+ {id++;printf("\nIdentifer");ECHO;}
[\+\*] {op++;printf("\nOperator");ECHO;}
"(" {v++;}
")" {v--;}
. {flag=1;}
\n {return 0;}
%%

int main()
{
printf("\n enter the arithmatic expression");
yylex();
if(((op+1)==id) && (v==0) && (flag==0))
{
printf("\nexpression is valid");
printf("\n no. of Identifers = %d",id);
printf("\n No of operators = %d\n",op);
}
else 
{
printf("\n invalid expression\n");
}
}
yywrap()
{
}
