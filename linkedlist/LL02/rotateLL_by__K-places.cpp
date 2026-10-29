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
 bool checkequal(Node* head1, Node*head2){
    while(head1 && head2 ){  // head1 && head2 iska mtlb hota hai not null
        if (head1->val != head2->val){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return(head1 ==NULL && head2 == NULL);
}
bool checkpalindrome(Node * head1){
    if(head1->next == NULL){
        return true;
    }
    //1. find the mid node
    Node * slow = head1;
    Node * fast = head1;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    //2. reverse the second half of LL
    Node *curr = slow;
    Node * pre = NULL;
    Node * next;
  while(curr){
    next = curr->next;  // 1. Agla node save karo
    curr->next = pre;   // 2. Link reverse karo
    pre = curr;         // 3. Previous ko aage badhao
    curr = next;        // 4. Current ko aage badhao
}
    //3. comparing the two half
    Node * head2 = pre;
    while(head2){
        if(head1->val != head2->val){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}
int main(){
    Node * head1 = NULL;
    insertatlast(head1, 1);
    insertatlast(head1, 3);
    insertatlast(head1, 3);
    insertatlast(head1, 1);
    display(head1);
    // Node * head2 = NULL;
    // Node* temp = head1;
    // while(temp){
    //     insertatlast(head2, temp->val);
    //     temp = temp->next;
    // }
    // reverse(head2);
    // if(checkequal(head1,head2)){ // if(CE) mean if true/1
    //     cout<<"palindrome"<<endl;
    // }
    // else{
    //     cout<<"Not palidrome"<<endl;}
    cout<<checkpalindrome(head1);
    
} 