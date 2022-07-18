%{
	#include<stdio.h>
	int c_count=0;
%}
%%
	"/*"[^(*/)]*"*/" {c_count++;}
	"//".* {c_count++;}
%%
int main(int argc,char **argv)
	{
	if (argc<3)
	{
		printf("enter the input and output files\n");
		exit(0);
	}
	yyin=fopen(argv[1],"r");
	if(!yyin)
	{
		printf("file error");
		exit(1);
	}
	yyout=fopen(argv[2],"w");
	yylex();
	printf("no.of comment lines:%d\n",c_count);
	return 0;
}
yywrap()
{
}

