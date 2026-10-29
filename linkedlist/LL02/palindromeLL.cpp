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
void rotatebyK(Node * &head, int k){
    Node * temp = head;
    int n = 1;
    while(temp->next){
        n++;
        temp = temp->next;
    }
    // temp is pointing to last node now afte find n
    k = k%n;
    if(k==0){
        return ;
    }
    //1. make lastnode point to head
    temp->next = head;
    //2. find n-k th node and make nixt node as new head
    temp = head;
    for(int i =1; i<(n-k); i++){
        temp = temp->next;
    }
    Node * newhead = temp->next; //n-k+1 ko naya head banaya;
    // 3. make n-k th node point to null;
    temp->next = NULL;
    // at last
    head  = newhead;

}
 
int main(){
    Node * head = NULL;
    insertatlast(head, 1);
    insertatlast(head, 2);
    insertatlast(head, 3);
    insertatlast(head, 4);
    display(head);
    rotatebyK(head,5);
    display(head);
   
}