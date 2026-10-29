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
    Node * newnode = new Node(value);
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
void reversell(Node* &head){
    Node* curr = head;
    Node * prev;
    while(curr!= NULL){
        prev = curr->pre;
        curr->pre = curr->next;
        curr->next = prev;
        curr = curr->pre;
    }
    head = prev->pre;
}

int main(){
Node * head = NULL;
insertAtend(head,1);
insertAtend(head,2);
insertAtend(head,3);
insertAtend(head,4);
insertAtend(head,5);
display(head);
reversell(head);
display(head);


}  

// Yaad rakhne ki trick 🧠
// - while(temp->next) → last node tak jaana hai.
// - while(temp) → saare nodes cross karke NULL tak jaana hai.