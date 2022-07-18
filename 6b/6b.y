%{
#include<stdio.h>
#include<stdlib.h>
int id=0,dig=0,key=0,op=0;
%}
%token DIGIT ID KEY OP
%%
input:DIGIT input{dig++;}
|ID input {id++;}
|KEY input {key++;}
|OP input {op++;}
|DIGIT {dig++;}
|ID {id++;}
|KEY {key++;}
|OP {op++;}
;
%%
extern FILE *yyin;
main()
{
FILE *myfile=fopen("sam_input.c","r");
if(!myfile)
{
printf("file error \n");
return -1;
}
yyin=myfile;
do
{
yyparse();
}
while(!feof(yyin));
printf("NUMBERS = %d\nKEYWORDS = %d\nIDENTIFIERS =%d\nOPERATORS =%d\n",dig,key,id,op);
}
void yyerror()
{
printf("parse error");
exit(-1);
}

