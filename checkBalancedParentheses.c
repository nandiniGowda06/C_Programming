
#include <stdio.h>
#include <string.h>
#include  <limits.h>
int top = -1;
char stackArray[50];

void push (int a )
{
    stackArray[++top] = a;
}

int pop()
{
    if (top >= 0){
    return stackArray[top--];
    }
    else{
        return -1;
    }
}
int main(int argc, const char * argv[]) {

    char inputstring[20];
    int i =0, isValid = 1;
    printf("Enter the expression to check valid parentheses\n");
    scanf("%s",inputstring);
    
    while (inputstring[i] != '\0') {
        char statcktop;
        switch (inputstring[i]) {
            case '(':
            case '[':
            case '{':
                push(inputstring[i]);
                break;
            case ')':
            case ']':
            case '}':
               statcktop = pop();
                if ((inputstring[i] - statcktop) >2) {
                    isValid =  0;
                }
                
            default:
                break;
        }
       i++;
    }
    
    if (top != -1) {
        isValid = 0;
    }
    if (isValid) {
        printf("Balnced parentheses\n");
    }
    else{
        printf("Unbalanced parentheses\n");
    }
    return 0;
}
