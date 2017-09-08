//
//  main.c
//  DataStructureStack
//
//  Created by nandini on 9/6/17.
//  Copyright © 2017 abc. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include  <limits.h>
int top = -1;
char stackArray[10];

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

int getOperatorPrecdValue(char op)
{
    switch (op) {
        case '(':
            return 0;
            break;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case ')':
            return 4;
            
        default:
            return -1;
            break;
    }
}

int prcd(char op1, char op2)
{
// when ( & ) encounters nothing shud happen as all the operators in between are popped by now and we don't require any ( or ) in post or prefix expression
    if(op1 == '(' &&  op2 == ')'  ){
        return 0;
    }    
    // allow any operator to push if it is a ( on stack top or input
    if (op1 == '(' || op2 =='(') {
        return 0;
    }
    // when input is ')'start popping the all the contents hence -1
    if(op2 == ')'){
        return -1;
    }
    // other wise for any other operator use the given precedence above
    return  (getOperatorPrecdValue(op2) - getOperatorPrecdValue(op1));
}
void infixToPostFixExpression(char *s)
{
    char postFixString[50] =""; int i =0;
    
    while (*s != '\0') {
        int x = getOperatorPrecdValue(*s);
        if (x  == -1){
            postFixString[i++] = *s;
        }
        else {   
        while( top!= -1  && prcd( stackArray[top], *s) < 0 ){
            postFixString[i++] =  pop();  // c;
        }
            if(*s != ')' )  push(*s);
            else pop();
        }
        s++;
    }
    while (top != -1) {
        postFixString[i++] = pop();
    }
    printf("postfix string is %s",postFixString);
}
void infixToPrefixExpression(char s[50])
{
        int len = (int)(strlen(s)-1);
        for (int i =0 ; i <=len/2; i++) {
            char temp = s[i] , temp2 = s[len-i] ;
            if (temp == '(') {
                temp = ')';
            }
            else if(temp == ')'){
                temp = '(';
            }
            if (temp2 == '(') {
             temp2 = ')';
            }
            else if (temp2 == ')'){
                temp2 = '(';
            }
            s[i] =  temp2;
            s[len-i] = temp;
        }
    char postFixString[50] =""; int i =0;
    while (*s != '\0') {
        int x = getOperatorPrecdValue(*s);
        if ( x  == -1)
        {
            postFixString[i++] = *s;
        }
        else {
            
            while( top!= -1  && prcd( stackArray[top], *s) < 0 ){
                postFixString[i++] =  pop();  // c;
            }
            if(*s != ')' )  push(*s); // to avoid closing brace insert
            else pop();// to avoid opening braces already insert
        }
        s++;
    }
    while (top != -1) {
        postFixString[i++] = pop();
    }
    printf("Prefix exprssion is\n");
    for (int i =(int) strlen(postFixString)-1; i>=0; i--) {
        printf("%c",postFixString[i]);
    }
}

void pushstring(char stringStack[][50] , char* value )
{
     strcpy( stringStack[++top], value) ;
}

char* popstring(char stringStack[][50])
{
    return stringStack[top--];
}
void postfixToInfixExpression(char *s)
{
    
    char stringStack[20][50];
    
    for (int j =0 ; j <strlen(s) ; j++) {
        int x = getOperatorPrecdValue(s[j]);
        if (x!= -1  && top != -1) {
            char c = s[j];
            char *temp =(char*) malloc(sizeof(char));
            *temp = c;
            char inFixString[50] ="";
            char *op2 = popstring(stringStack);
            char *op1 = popstring(stringStack);
            strcat(inFixString, "(");
            strcat(inFixString, op1);
            strcat(inFixString, temp);
            strcat(inFixString, op2);
            strcat(inFixString,")");
            pushstring(stringStack, inFixString);
        }
        else
        {
            char c = s[j];
            char *temp =(char*) malloc(sizeof(char));
            *temp = c;
            pushstring(stringStack,temp);
        }
    }
     printf("Infix Expression is %s",  popstring(stringStack));
}

void prefixToInfixExpression(char *s)
{
   
    char stringStack[20][50];
    // same as postfix to infix reverse the order
    for (int j =(int) strlen(s)-1 ; j >= 0 ; j--) {
        int x = getOperatorPrecdValue(s[j]);
        if (x!= -1  && top != -1) {
            char c = s[j];
            char *temp =(char*) malloc(sizeof(char));
            *temp = c;
            char inFixString[50] ="";
            char *op1 = popstring(stringStack); // order changed as its reading reverse
            char *op2 = popstring(stringStack);
            strcat(inFixString, "(");
            strcat(inFixString, op1);
            strcat(inFixString, temp);
            strcat(inFixString, op2);
            strcat(inFixString,")");
            pushstring(stringStack, inFixString);
        }
        else
        {
            char c = s[j];
            char *temp =(char*) malloc(sizeof(char));
            *temp = c;
            pushstring(stringStack,temp);
        }
    }
    printf("Infix Expression is %s",  popstring(stringStack));

}


void postToPrefixExpression(char *s)
{
    char stringStack[20][50];
    for (int j =0 ; j <strlen(s) ; j++) {
        int x = getOperatorPrecdValue(s[j]);
        if (x!= -1  && top != -1) {
            char c = s[j];
            char *temp =(char*) malloc(sizeof(char));
            *temp = c;
            char inFixString[50] ="";
            char *op2 = popstring(stringStack);
            char *op1 = popstring(stringStack);
            strcat(inFixString, temp); // prefic conversion place operator before operands
            strcat(inFixString, op1);
            strcat(inFixString, op2);
            pushstring(stringStack, inFixString);
        }
        else
        {
            char c = s[j];
            char *temp =(char*) malloc(sizeof(char));
            *temp = c;
            pushstring(stringStack,temp);
        }
    }
    printf("Prefix Expression is %s",  popstring(stringStack));
}
void preToPostfixExpression(char *s)
{
    char stringStack[20][50];
    for (int j = (int)strlen(s)-1 ; j >= 0 ; j--) {
        int x = getOperatorPrecdValue(s[j]);
        if (x!= -1  && top != -1) {
            char c = s[j];
            char *temp =(char*) malloc(sizeof(char));
            *temp = c;
            char inFixString[50] ="";
            char *op2 = popstring(stringStack);
            char *op1 = popstring(stringStack);
            strcat(inFixString, op2);
            strcat(inFixString, op1);
            strcat(inFixString, temp); // post conversion place operator after operands
            pushstring(stringStack, inFixString);
        }
        else
        {
            char c = s[j];
            char *temp =(char*) malloc(sizeof(char));
            *temp = c;
            pushstring(stringStack,temp);
        }
    }
    
    printf("Prefix Expression is %s",  popstring(stringStack));
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    char inputString[50] ;
    int choice = -1 , retry = -1;
    do {
    printf("1.Infix to Postfix\n");
    printf("2.Infix to Prefix\n");
    printf("3.Postfix to Infix\n");
    printf("4.Postfix to Prefix\n");
    printf("5.Prefix to Infix\n");
    printf("6.Prefix to Postfix\n");
    printf("Enter the choice of your prefernce to convert \n");
    scanf("%d",&choice);

    switch (choice) {
        case 1:
            printf("Enter valid Infix expression");
            scanf("%s",inputString);
            infixToPostFixExpression(inputString);
            break;
        case 2 :
            printf("Enter valid Infix expression");
            scanf("%s",inputString);
            infixToPrefixExpression(inputString);
            break;
        case 3:
            printf("Enter valid Postfix expression");
            scanf("%s",inputString);
            postfixToInfixExpression(inputString);
            break;
        case 4:
            printf("Enter valid Postfix expression");
            scanf("%s",inputString);
            postToPrefixExpression(inputString);
            break;
        case  5:
            printf("Enter valid Prefix expression");
            scanf("%s",inputString);
            prefixToInfixExpression(inputString);
            break;
        case 6:
            printf("Enter valid Prefix expression");
            scanf("%s",inputString);
            preToPostfixExpression(inputString);
            break;
        default:
            printf("Invalid choice, Press 1 to retry ");
            scanf("%d",&retry);
            break;
    }
        
    } while (retry == 1);

    return 0;
}
