#include<iostream>
using namespace std;
class Node{
    public :
     int value;
     Node *next;
     Node (int value){
        this->value = value;
        next = NULL;
     }

};
class Mystack{
    Node * head;
    Node * tail;
    int len;
    public:
    Mystack(){
        head = tail = NULL;
        len = 0;
    }
    void push(int value){
        Node * n = new Node(value);
        n->next = head;
        head = n;
        len++;

    }
    void pop(){
        if(len == 0){
            cout<<"stack is empty"<<endl;
        }
        Node * tobedeleted = head;
        head = head->next;
        delete tobedeleted;
        len--;

    }
    int get(){
        return head->value;
    }
    int size(){
        return len;
    }
    void display(){
        Node * temp = head;
        while(temp){
            cout<<temp->value<<"-->";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};
int main(){
    Mystack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.pop();
    st.display();
}