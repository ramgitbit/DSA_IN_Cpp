#include<iostream>
using namespace std;
class Node{  //useer define date typpe
    public:
    int val;
    Node* next;
    Node(int val){ 
         this->val = val;
         this->next = NULL;

    }
};
void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
void insertathead(Node* &head  , int val){ // & = pass by ref
    Node * newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}
void insertatlast(Node* &head, int val){
    if (head == NULL){
        insertathead(head,val);
        return;
    }
    Node * tailnode = new Node(val);
    Node * temp = head;
    while(temp->next != NULL){
        temp = temp->next ;
    }
    temp->next = tailnode;
    //tailnode->next = NULL;
}

void deleteatstart(Node* &head){
    if(head == NULL){
        return;
    }
    Node * temp = head;
    head = head->next;
    free(temp);
}
 void reverse(Node * &head1){
    Node * pre = NULL;
    Node* current = head1;
    Node* next;
    while(current){
        next= current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    head1 = pre;
 } 
int main(){
    Node * head1 = NULL;
    insertatlast(head1, 1);
    insertatlast(head1, 2);
    insertatlast(head1, 3);
    insertatlast(head1, 4);
    display(head1);
    reverse(head1);
    display(head1);
    
    
}