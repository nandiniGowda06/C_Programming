//
//  main.c
//  DataStructureTree
//
//  Created by nandini on 9/14/17.
//  Copyright © 2017 abc. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
// binary tree
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node Node;
Node * insert(Node *root)
{
    Node *temp,*cur, *prev = NULL;
    int item;
    printf("Enter the item to insert\n");
    scanf("%d",&item);
    temp = (Node*)malloc(sizeof(Node));
    temp->data = item;
    temp->right = NULL;
    temp->left = NULL;
    
    if(root){
        cur = root;
        while (cur) {
            prev = cur;
            if (item > cur->data) {
                cur = cur->right;
            }else{
                cur = cur->left;
            }
        }
        //  reaches the null node
        if (item < prev->data)
            prev->left = temp;
            else
                prev->right = temp;
        
        cur = temp;
        return root;
    }
    else{
        return temp;
    }
    return root;
}

void displayNodeInOrder(Node *root)
{
    if (root) {
        displayNodeInOrder(root->left);
        printf("%d ",root->data);
        displayNodeInOrder(root->right);
    }
}

Node * deleteNode(Node *root)
{
    Node *cur, *deleteSuc,*parent = NULL;
    
    // get the node to be deleted
    if (root) {
        int item;
        printf("Enter the item to be deleted\n");
        scanf("%d",&item);
        cur = root;
        // loop exits when node is null or when item found
        while (cur && cur->data != item) {
            parent = cur;
            if (item > cur->data ) {
                cur = cur->right;
            }
            else{
                cur = cur->left;
            }
        }
        // all nodes traverse yet no data found
        if (cur == NULL){
            printf("Data does not exits, try with existing data\n");
            return root;
        }
        // case 1 the delete node has left subtree so this will become left of its parent
        if (cur -> right == NULL) {
            deleteSuc = cur->left;
        }
        // case 2 the delete node has left subtree so this will become left of its parent
    // these 2 condiitons will also suffice if both the tree are empty
        else if (cur->left == NULL){
            deleteSuc = cur->right;
        }
        // in this case the delete node has both right and left subtree. so always get the next elt of inorder traversal, and make it new subtree attach to the parent
        else
        {
            Node *leftMostNode , *temp = cur->right;
            while (temp->left) {
                temp = temp->left;
            }
            // becase it is right tree this has greater value than the left tree of the cur
            leftMostNode = temp;
            leftMostNode->left = cur->left;
            deleteSuc = cur->right;
        }
        
        // now make this delete suc to the parent node
        // if root node is deleted
        if (parent == NULL) {
            return deleteSuc;
        }
        
        if (parent->left == cur) {
            parent->left = deleteSuc;
        }
        else {
            parent->right = deleteSuc;
        }
        
        free(cur);
        
        return root;
    }
    else
    {
        printf("Tree is empty\n");
    }
    return root;
}

int main(int argc, const char * argv[]) {
  
    int choice;
    Node *root = NULL;
    for (; ; ) {
        printf("Enter choice for Binary Tree\n");
        printf("1.Insert \n");
        printf("2.Display\n");
        printf("3.Delete node\n");
        printf("4.Exit\n");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
               root = insert(root);
                break;
            case 2:
                displayNodeInOrder(root);
                break;
            case 3:
                root = deleteNode(root);
                break;
            case 4:
                return 0;
                break;
            default:
                return 0;
                break;
        }
    }
    
    
    return 0;
}
