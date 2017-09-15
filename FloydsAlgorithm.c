
// Node is struct data type 
/*
 struct node
 {
 int data; 
 struct node *next; 
 };
 
 typedef struct node Node; 
*/

// head is pointer to the head node of the linked list  

int hasCycle(Node *head)
{
  Node *fast, *slow; 
  slow = head; 
  fast = (head->next)->next; 
  while(slow && fast)
  {
       if(slow == fast) return 0; 
       else {
       slow = slow->next; 
       fast = fast->next; 
       }
  }
  return 1; 
}

