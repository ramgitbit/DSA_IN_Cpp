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
void deleteAlternatives(Node * &head){
    Node * temp = head;
    while(temp != NULL && temp->next != NULL){
    temp->next = temp->next->next;
    temp = temp->next;
}}
int main(){
    Node * head = NULL;
    insertathead(head, 5);
    insertathead(head, 4);
    insertathead(head, 3);
    insertathead(head, 2);
    insertathead(head, 1);
    display(head);
    deleteAlternatives(head);
    display(head);
   
    
}