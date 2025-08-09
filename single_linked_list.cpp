#include <iostream>
using namespace std;

//Class for Node of single linked list
class Node{
public:
  int data;
  Node *next;
  Node(int data){
    this->data=data;
    this->next=NULL;
    
  }
  ~Node(){
    //int value=this->data;
    if(this->next!=NULL){
      delete next;
      this->next =NULL;
    }
    //cout <<"Memory is free for node with data " << value <<endl; 
  }
};

bool searchNode(Node *head,int key){//Time Complexity : O(n)
  if(head==NULL){
    return false;
  }
  Node*curr = head;
  while(curr!=NULL){
    if(curr->data==key){
      return true;
    }
    curr=curr->next;
  }
  return false;
}

void insertAtHead(Node* &head,int data){//Time Complexity : O(1)
  Node *temp = new Node(data);
  if(head==NULL){
    head=temp;
  }
  else{
    temp->next = head;
    head=temp;
  }

}
void insertAtEnd(Node* &head,Node *&tail,int data){
  if(head==NULL){
    insertAtHead(head,data);
  }
  Node *temp= new Node(data);
  Node *curr = head;
  while(curr->next!=NULL){
    curr=curr->next;
  }
  curr->next = temp;
  tail=temp;
  
  
}
void insertAtMiddle(Node* &head,Node* &tail,int pos,int data){
  if(pos==1){
    insertAtHead(head,data);
    return;
  }
  Node *temp = new Node(data);
  Node *curr = head;
  int cnt=1;
  while(cnt<(pos-1)){
    curr=curr->next;
    cnt++;
  }
  if(curr->next==NULL){
    insertAtEnd(head,tail,data);
    return;
    
  }
  temp->next=curr->next;
  curr->next =temp;
}
void deleteNodeByPosn(Node* &head,Node* &tail,int pos){
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  if(pos==1){
    Node*temp = head;
    head=temp->next;
    temp->next = NULL;
    delete temp;
    return;
  }
  Node *curr = head;
  int cnt =1;
  while(cnt<pos-1 && curr->next !=NULL){
    curr=curr->next;
    cnt++;
  }
  if(curr->next ==NULL) return;
  Node *temp = curr->next;
  curr->next = temp->next;
  temp->next = NULL;

  if(tail==temp){
    tail=curr;
    
  }
  delete temp;
  
}
void updateNode(Node* &head,int key,int data){
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  Node *curr = head;
  while(curr!=NULL){
    if(curr->data==key){
      curr->data=data;
      return;
    }
    curr=curr->next;
  }
  if(curr==NULL){
    cout<<"Key not found"<<endl;
  }
}
void reverseList(Node* &head,Node* &tail){
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  Node*curr = head;
  Node*prev = NULL;
  Node*next = NULL;
  tail=head;
  while(curr!=NULL){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }
  head=prev;
}
int length(Node*head){
  int cnt=0;
  Node *temp = head;
  while(temp!=NULL){
    cnt++;
    temp=temp->next;
  }
  return cnt;
}
void operations(Node*&head,Node*&tail){
  insertAtHead(head,10);
  insertAtEnd(head,tail,20);
  insertAtHead(head,100);
  insertAtMiddle(head,tail,1,0);
  insertAtMiddle(head,tail,8,-1);
  deleteNodeByPosn(head,tail,1);
  deleteNodeByPosn(head,tail,5);
  deleteNodeByPosn(head,tail,6);

}
void print(Node*head,Node*tail){//Time Complexity : O(n)
  if(head==NULL){
    cout << "List is empty" <<endl;
    return;
  }
  else{
    cout<<"Head:"<<head->data<<endl;
    while(head!=NULL){
      cout << head->data << " ";
      head=head->next;
    }
  }
  cout<<endl;
  
  cout<<"Tail:"<<tail->data<<endl;
}
int main(){
  Node *head= NULL;
  
  Node*tail = NULL;
  Node*node1 = new Node(1);
  Node*node2 = new Node(3);
  Node*node3 = new Node(2);
  head=node1;
  tail=node3;
  node1->next=node2;
  node2->next=node3;
  operations(head,tail);
  print(head,tail);
  cout<<"Reverse Linked LIst"<<endl;
  reverseList(head,tail);
  print(head,tail);
  cout << "Length of linked list: "<<length(head) <<endl;

}
