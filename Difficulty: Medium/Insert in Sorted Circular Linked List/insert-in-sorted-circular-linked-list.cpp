

/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */
 
// This function should return head of
// the modified list
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       //Your code here
       Node* temp=head;
      Node* n=new Node(data);
      if(head==NULL){
          head=n;
          n->next=head;
      }
      else if(temp->data>(data)){
          while(temp->next!=head)
          {
              temp=temp->next;
          }
          n->next=head;
          temp->next=n;
          head=n;
      }
      else{
      while(temp->next->data<data && temp->next!=head){
          temp=temp->next;
      }
      n->next=temp->next;
      temp->next=n;
      }
      return head;
       
    }
};
