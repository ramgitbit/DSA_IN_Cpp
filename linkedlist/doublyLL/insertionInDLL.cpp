#include<iostream>
using namespace std;
class Node{  //useer define date typpe
    public:
    int val;
    Node* next;
    Node * pre;
    Node(int val){ 
         this->val = val;
         this->next = NULL;
         this->pre = NULL;

    }
};
void display(Node * head){
    Node * temp = head;
    while(temp){
        cout<<temp->val<<"<-->";
        temp = temp->next;

    }
    cout<<"NULL"<<endl;
}

void insertatStart(Node * &head, int value){
    Node * newnode = new Node(value);
      if(head == NULL){
        head = newnode;
        return;
    }
    //Node* temp = head;
    newnode->next = head;
    //temp->pre = newnode;
    head->pre = newnode;
    head = newnode;

}
void insertAtend(Node*  &head, int value){
    Node * newnode = new Node(4);
    if(head == NULL){
        head = newnode;
        return;
    }

    Node * temp = head;
    while(temp->next){
        temp= temp->next;
    }
    temp->next = newnode;
    newnode->pre = temp;
}
void insertAtMid(Node* &head, int value,int pos){
    if (pos == 1){
        insertatStart(head,value);
        return;
    }
     Node * newnode = new Node(value);
     Node * temp =  head; 
     for(int i =1; i< pos-1; i++){
        temp = temp->next;
     }
     if(temp->next ==NULL){
        temp->next->pre = newnode;
     }
     newnode->next = temp->next;
     temp->next = newnode;
     newnode->pre = temp;
}
void deleteAtStart(Node * &head){
    if(head->next == NULL){
        // if head == NULL or head->next  == NULL;
free(head);
return;
    }
    head = head->next;
    head->pre = NULL;

    // Node*temp = head;
    // temp= temp->next;
    // temp->pre = NULL;
    // temp = head;
    //temp head ka copy hai, isliye temp ko change karne se original head change nahi hota.
      
}
void deleteAtEnd(Node* &head) {
    // Case 1: Empty linked list
    if (head == NULL) {
        return;
    }
    // Case 2: Only one node
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    // Case 3: Multiple nodes
    Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }
   Node* last = temp->next;  // last = node 30
    temp->next = NULL;        // node 20 ka next = NULL
    delete last;              // node 30 ki memory free
}
void deleteAtMid(Node* &head , int pos){
    if(pos==1){
        deleteAtStart(head);
        return;
    }
    Node * temp = head;
    for(int i =1; i<pos-1; i++){
        temp = temp->next;
    }
    Node * delNode = temp->next;
    temp= delNode->next;
    if(delNode->next != NULL){
        delNode->next->pre = temp;
    }
    free(delNode);
}
int main(){
 Node * n1 = new Node(1);
 Node * n2 = new Node(2);
 n1->next = n2;
 n2->pre = n1;
 Node * head = n1;
 display(head);
 insertatStart(head, 3);
 display(head);
 insertAtend(head , 4);
 display(head);
 insertAtMid(head, 99, 1);
 display(head); 
 deleteAtStart(head);
 display(head);
 deleteAtEnd(head);
 display(head);
 deleteAtMid(head, 2);
 display(head);

}  

// Yaad rakhne ki trick 🧠
// - while(temp->next) → last node tak jaana hai.
// - while(temp) → saare nodes cross karke NULL tak jaana hai.