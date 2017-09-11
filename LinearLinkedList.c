//
//  main.c
//  DataStructureLinkedList
//
//  Created by nandini on 9/10/17.
//  Copyright © 2017 abc. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *next;
};

typedef struct node Node ;

Node* getNode()
{
    Node *p = (Node *)malloc(sizeof(Node));
    
    if (p== NULL) {
        
        printf("Out of memory\n");
    }
    
    return p;
}
Node* insertNode(Node *list)
{
    Node *current = getNode();
    
    if (current != NULL) {
        int item;
        printf("Enter the item to insert\n");
        scanf("%d",&item);
        current->item = item;
        current->next = list;
    }
    return current;
    //        list = current;

    
}

void removeNode(Node *list)
{
    Node* temp = list->next;
    free(list);
    list = temp;
}

void displayNode(Node *list)
{
    Node *temp = list;
    while (temp!= NULL) {
    
        printf("%d\n",temp->item);
        temp = temp->next;
    }
}

int main(int argc, const char * argv[]) {
   
    int choice;
    Node *list = NULL;
   
    printf("Linear linked list operations\n");
    printf("1.Insert Node\n");
    printf("2.Remove Node\n");
    printf("3.Display node contents\n");
    printf("4.Exit\n");
    
    for (; ;) {
        printf("Enter choice\n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
               list = insertNode(list);
                break;
            case 2:
                removeNode(list);
                break;
            case 3:
                displayNode(list);
                break;
            default:
                return 0;
                break;            
        }
    }
    return 0;
}












