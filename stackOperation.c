#include <stdio.h> 

#define  STACKSIZE 5 

struct structstack
{
    int top;
    int items[STACKSIZE];
};

typedef  struct structstack STACK;


int isStackFull(STACK *s)
{
    if (s->top >= STACKSIZE-1) {
        return 1;
    }
    else{
        return 0;
    }
}
int isStackEmpty(STACK *s)
{
    if (s->top == -1) {
        return 1;
    }
    else{
        return 0;
    }
}

void structstackPush(int item , STACK *s)
{
    if (isStackFull(s)) {
        printf("Stack is full\n");
        return;
    }
    else{
        s->items[++(s->top)] = item;
    }
}

int structstackPop(STACK *s)
{
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        return 0;
    }
    else {
     return  s->items[(s->top)--];
    }
}
void displayStackElements(STACK *s)
{
    printf("Stack elements\n");
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        return ;
    }
    else {
    for (int i = s->top ; i >= 0 ; i--) {
        printf("%d\n",s->items[i]);
    }
    }
}
int main(int argc, const char * argv[]) {

    STACK s;
    s.top = -1;
    int choice, item;
    printf("Stack Operation\n");
    printf("1.Push \n");
    printf("2.Pop \n");
    printf("3.Display \n");
    printf("4.Exit \n");
    
    for(;;)
    {
    printf("Enter  your choice\n");
    scanf("%d",&choice);
    
    switch (choice) {
        case 1:
            printf("Enter the item to Push\n");
            scanf("%d",&item);
            structstackPush(item, &s);
            break;
        case 2:
            printf("Poped item is %d\n", structstackPop(&s));
            break;
        case 3:
            displayStackElements(&s);
            break;
        case 4:
            return 0;
        default:
            return 0;
            break;
    }
    }
    return 0;
}
