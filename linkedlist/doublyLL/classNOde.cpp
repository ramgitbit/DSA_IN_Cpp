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
void backwarddisplay(Node * head){
    Node * temp = head;
    while(temp->next){ // temp yaha last par hoga temp->next NULL pe hoga
        temp = temp->next; // iss loop se temp last node pe aa gaya hoga
    }
    while(temp){
    cout<<temp->val<<"<-->";
    temp= temp->pre;
    }
     cout<<"NULL"<<endl;
}
int main(){
 Node * n1 = new Node(1);
 Node * n2 = new Node(2);
 n1->next = n2;
 n2->pre = n1;
 Node * head = n1;
 display(head);
 backwarddisplay(head);
}  

// Yaad rakhne ki trick 🧠
// - while(temp->next) → last node tak jaana hai.
// - while(temp) → saare nodes cross karke NULL tak jaana hai.