/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
    if(head == nullptr)
        return nullptr;
    Node* temp = head;
    head = head->next;
    Node* newHead = Reverse(head);
    if(newHead == nullptr)
        return temp;
    temp->next = nullptr;
    head->next = temp;
    return newHead;
}

