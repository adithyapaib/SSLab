#include <stdio.h>
#include <string.h>
int k = 0, z = 0, i = 0, j = 0, c = 0;
char a[25], ac[20], stk[15], act[10];
void check();

void printOP(int z)
{
    stk[z] = 'E';
    stk[z + 1] = '\0';
    stk[z + 2] = '\0';
    printf("\n$%s \t %s$\t %s", stk, a, ac);
    i = i - 2;
}

void main()
{
    puts("Enter input string ");
    gets(a);
    c = strlen(a);
    strcpy(act, "SHIFT");
    puts("Stack \t Input \t Action");
    for (k = 0, i = 0; j < c; k++, j++, i++)
    {
        if (a[j] == 'i' && a[j + 1] == 'd')
        {
            stk[i] = a[j];
            stk[i + 1] = a[j + 1];
            stk[i + 2] = '\0';
            a[j] = ' ';
            a[j + 1] = ' ';
            printf("\n$%s \t %s$\t %s", stk, a, act);
            check();
        }
        else
        {
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j] = ' ';
            printf("\n$%s \t %s$\t %s symbols", stk, a, act);
            check();
        }
    }
}

void check()
{
    strcpy(ac, "REDUCE TO E");
    for (z = 0; z < c; z++){
        if (stk[z] == 'i' && stk[z + 1] == 'd')
        {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            printf("\n$%s \t %s$\t %s", stk, a, ac);
            j++;
        }
        if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E')
            printOP(z);
        if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E')
            printOP(z);
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')')
            printOP(z);
        
    }
}
