#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

FILE *fp1, *fp2;

void movef(char arg1[5],int op,  char arg2[5], char result[5]){
    fprintf(fp2, "\n MOV R0 %s", arg1);
    if(op==1)
     fprintf(fp2, "\n ADD R0 %s", arg2);
    else if(op==2)
     fprintf(fp2, "\n SUB R0 %s", arg2);
    else if(op==3)
     fprintf(fp2, "\n MUL R0 %s", arg2);
    else if(op==4)
     fprintf(fp2, "\n DIV R0 %s", arg2);
    fprintf(fp2, "\n MOV %s R0", result);
}

char op[2], arg1[5], arg2[5], result[5];
void main()
{
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");
    while (!feof(fp1))
    {
        fscanf(fp1, "%s%s%s%s", result, arg1, op, arg2);
        if (strcmp(op, "+") == 0)
            movef(arg1, 1, arg2, result);
        else if (strcmp(op, "-") == 0)
            movef(arg1, 2, arg2, result);
        else if (strcmp(op, "*") == 0)
            movef(arg1, 3, arg2, result);
        else if (strcmp(op, "/") == 0)
            movef(arg1, 4, arg2, result);
        else if (strcmp(op, "=") == 0)
            movef(arg1, 0, arg2, result);
        else if (strcmp(op, "=") == 0)
           movef(arg1, 9, arg2, result);
    }
    fclose(fp1);
    fclose(fp2);
}
