#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char prod[3][10] = {"A->aBa", "B->bB", "B->@"}, input[20], stack[30];
int top =-1, j=0, l , k ;

void pop(){
    top = top-1;
}
void push(char p){
    stack[++top] = p;
}

void stackpush(char p){
    if(p == 'A'){
        pop();
        for(j=5;j>=3;j--)
            push(prod[0][j]);
    }else{
         pop();
        for(j=4;j>=3;j--)
            push(prod[1][j]);
    }
}

void main(){
    printf("\nFirst(A) = {a} \t Follow (A)= {$}");
    printf("\nFirst(B) = {b,@} \t Follow (A)= {a}");
    printf("\n\t\t a \tb \t$");
    printf("\n\t\t %s  \t",prod[0]);
    printf("\n\t\t\t %s  \t %s",prod[2], prod[1]);
    int i;
    printf("\nEnter a string with $ as send marker :");
    scanf("%s",input);
    for(i=0;input[i]!='\0';i++){
        if(input[i]!='a'&&input[i]!='b'&&input[i]!='$'){
            printf("Invalid string");
            exit(0);
        }
    }
    if(input[i-1]!='$'){
       printf("Invalid string");
            exit(0);
    }

    push('$');
    push('A');
    i=0;
     printf("Stack \t Input \t Action");
    while(i!=strlen(input) && stack[top] !='$'){
        printf("\n");
        for(l=top;l>=0;l--)
                 printf("%c",stack[l]);
        printf("\t");
        for(l=i;l<strlen(input);l++)
                 printf("%c",input[l]);
        if(stack[top] == 'A'){
            printf("A->aBa\n");
            stackpush('A');
        }else if(stack[top] =='B'){
            if(input[i]!='b'){
                 printf("B->@\n");
                 printf(" matched  @");
                 pop();
            }else{
                printf("b->bB\n");
            stackpush('B');

            }

        }
        else{
            if(stack[top] == input[i]){
                printf("pop %c",input[i]);
                 printf(" matched  @");
                 pop();
                 i++;

            }else
                break;

        }

            
        
    }
     if (stack[top] == '$' && input[i] == '$')
        // Stack only has $
         printf("\n$ \t\t $ \nValid Expression");
    
           
        else
            printf("\nInvalid Exp");

}
