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
void insertatmid(Node * & head, int val, int pos){
    if(pos == 1){
        insertathead(head,val);
        return;
    }
    Node * newnode = new Node(val);
    Node * pre = head;
    int count = 1;
    while(count < (pos-1)){
        pre = pre->next;
        count++;
    }
    newnode->next = pre->next;
    pre->next = newnode;

}
void deleteatstart(Node* &head){
    if(head == NULL){
        return;
    }
    Node * temp = head;
    head = head->next;
    free(temp);
}
void deleteatlast(Node * &head){
    if (head == NULL){
        return;
    }
    if (head ->next == NULL){
        deleteatstart(head); ///jab bs ek  hi element ho 
    }
    Node * temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
}
void deleteatmid(Node* & head , int pos){
    if (pos == 1){
        deleteatstart(head);
        return;
    }
    Node * temp = head;
     int count  = 1;
     while(count < (pos-1)){
        temp = temp->next;
        count++;
     }
     temp->next = temp->next->next;

}
void updatenode(Node* &head , int pos,int val){
    Node* temp = head;
    int count = 1;
    while(count < pos){
        temp = temp->next;
        count++;
    }
    temp->val = val;
}
int main(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1->next = node2;
    Node*head = node1;
    display(head);
    insertathead(head, 3);
    display(head);
    insertatlast(head,4);
    display(head);
    insertatmid(head,5,3);
    display(head);
    deleteatstart(head);
    display(head);
    deleteatlast(head);
    display(head);
    deleteatmid(head,2);
    display(head);
    updatenode(head,1,10);
    display(head);
}