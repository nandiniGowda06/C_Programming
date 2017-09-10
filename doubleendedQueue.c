//
//  main.c
//  DatastructureQueue
//
//  Created by avinash on 9/9/17.
//  Copyright © 2017 abc. All rights reserved.
//

#include <stdio.h>
#define QUEUE_SIZE 5

struct queue{
    
    int front;
    int rear;
    char items[QUEUE_SIZE][10];
};

// double ended QUEUE

#define QUEUE struct queue

void insertRearEnd( QUEUE * q)
{
    if (q->rear == QUEUE_SIZE-1) {
        printf("Queue overflow\n");
    }
    else {
        char item[10];
        printf("Enter the string to insert\n");
        scanf("%s",item);
        strcpy(q->items[(++(q->rear))] , item);
    }
}
void insertFrontEnd(QUEUE *q)
{
    char item[10];
    printf("Enter the string to insert\n");
    scanf("%s",item);
    
    if (q->front > 0 ) {
        strcpy(q->items[--(q->front)], item);
        return;
    }
     if ( q->front == 0  && q->rear == -1) {
        strcpy( q->items[++(q->rear)],item);
         return;
     }
   
    printf("queue front isertion failed\n");
}
void removeFrontEnd(QUEUE *q)
{
    if (q->front > q->rear)
    {
        printf("Queue is underflow\n");
        return;
    }
    printf("first item in queue is %s\n",q->items[( q->front)++]);
    
    if (q->front > q->rear) {
        q->front = 0;
        q->rear = -1;
    }
  
}
void removeRearEnd(QUEUE *q)
{
    
    if (q->front > q->rear ) {
        printf("Queue is underflow\n");
        return;
    }
    
    printf("first item in queue is %s\n",q->items[( q->rear)--]);
       if (q->front > q->rear) {
        q->front = 0;
        q->rear = -1;
    }
}
void displayQueueContents(QUEUE *q)
{
    for (int i = q->front; i <= q->rear; i++) {
        printf("%s\n",q->items[i]);
    }
}
int main(int argc, const char * argv[]) {
    
    int choice;
    QUEUE q;

    q.front = 0;
    q.rear = -1;
    
    printf("Below are the operations for simple Queue\n");
    printf("1.Insert from front end to queue\n");
    printf("2.Insert from rear end to queue\n");
    printf("3.Remove from front end of queue\n");
    printf("4.Remove from rear end of queue\n");
    printf("5.Display queue contents\n");
    printf("6.Exit\n");
    for (;;) {
        printf("Enter the choice\n");
        scanf("%d",&choice);
       
        switch (choice) {
            case 1:
                insertFrontEnd(&q);
                break;
            case 2:
                insertRearEnd(&q);
                break;
            case 3:
                removeFrontEnd(&q);
                break;
            case 4:
                removeRearEnd(&q);
            case 5:
                displayQueueContents(&q);
                break;
            default: return 0;
                break;
        }
    }
    return 0;
}
