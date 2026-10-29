#include<iostream>
#include<stack> // stack is truly unlimited like LL
// Sabse pehle ye difference yaad rakho:
//- Indexing: 0 se counting start hoti hai.
//- Position: 1 se counting start hoti hai.

using namespace std;
void printTopToBottom(stack<int> &st){
stack<int> helper;
while (st.size()>0){
    cout<<st.top()<<" ";
    helper.push(st.top());
    st.pop();
}
// put back elem from helper to st;
while ((helper.size()>0)){
   st.push(helper.top());
   helper.pop(); 
}
 cout<<endl;
}
void push (stack<int> &st, int val, int pos){
stack<int> helper;
while (st.size()>pos)
{
 helper.push(st.top());
 st.pop();
}
st.push(val);
while (helper.size()>0)
{
    st.push(helper.top());
    helper.pop();
}

}
void pop(stack<int> &st,  int pos){
stack<int> helper;
while (st.size()-1>pos)
{
 helper.push(st.top());
 st.pop();
}
//st.pop();
if (!st.empty()) {
    st.pop();
}
while (helper.size()>0)
{
    st.push(helper.top());
    helper.pop();
}
}
void get(stack<int> &st,  int pos){
stack<int> helper;
while (st.size()-1>pos)
{
 helper.push(st.top());
 st.pop();
}
cout<<st.top();
while (helper.size()>0)
{
    st.push(helper.top());
    helper.pop();
}

}

int main(){
    stack<int> st;
    st.push(10);// add top 
    st.push(20);
    st.push(30);
    st.push(40);
    push(st, 500, 0);
    printTopToBottom(st);
    pop(st,2);
    printTopToBottom(st);
    get(st,0);
    
    
    
 
}