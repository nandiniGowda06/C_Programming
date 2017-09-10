//
//  main.c
//  DatastructureQueue
//
//  Created by nandini on 9/9/17.
//  Copyright © 2017 abc. All rights reserved.
//

#include <stdio.h>
#define QUEUE_SIZE 5

struct queue{
    
    int front;
    int rear;
    int item_count;
    char items[QUEUE_SIZE][10];
};

// circular QUEUE : efficint use of size

#define QUEUE struct queue

void insertRearEnd( QUEUE * q)
{
    if (q->item_count == QUEUE_SIZE) {
        printf("Queue overflow\n");
    }
    else {
        char item[10];
        printf("Enter the string to insert\n");
        scanf("%s",item);
        
        (q->rear) = ((q->rear)+1) % QUEUE_SIZE;
        
        strcpy(q->items[q->rear] , item);
        
        q->item_count++;
    }
}
void removeFrontEnd(QUEUE *q)
{
    if (q->item_count == 0)
    {
        printf("Queue is underflow\n");
        return;
    }
   
    printf("first item in queue is %s\n",q->items[( q->front)]);
    
    q->front = ((q->front)+1) % QUEUE_SIZE;
    q->item_count --;
}

void displayQueueContents(QUEUE *q)
{
    for (int i = (q->front); i <= q->item_count; i++) {
        printf("%s\n",q->items[(i % QUEUE_SIZE)]);
    }
}
int main(int argc, const char * argv[]) {
    
    int choice;
    QUEUE q;

    q.front = 0;
    q.rear = -1;
    q.item_count =0;
    
    printf("Below are the operations for Circular Queue\n");
    printf("1.Insert to queue\n");
    printf("2.Remove from queue\n");
    printf("3.Display queue contents\n");
    printf("4.Exit\n");
    for (;;) {
        printf("Enter the choice\n");
        scanf("%d",&choice);
       
        switch (choice) {
            case 1:
                insertRearEnd(&q);
                break;
            case 2:
                removeFrontEnd(&q);
                break;
            case 3:
                displayQueueContents(&q);
                break;
            default: return 0;
                break;
        }
    }
    return 0;
}
