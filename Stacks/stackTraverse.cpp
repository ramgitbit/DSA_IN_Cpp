#include<iostream>
#include<stack> // stack is truly unlimited like LL
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
void printBottomToTop(stack<int> &st){
stack<int> helper;
while (st.size()>0){
    helper.push(st.top());
    st.pop();
}
// put back elem from helper to st;
 while ((helper.size()>0)){
   /// helper me elem bottom to top hai to isko print kara 
   cout<<helper.top()<<" ";
   st.push(helper.top());
   helper.pop(); 
}
cout<<endl;

}
int main(){
    stack<int> st;
    st.push(10);// add top 
    st.push(20);
    st.push(30);
    st.push(40);
    printTopToBottom(st);
    printTopToBottom(st);
    printBottomToTop(st);
    
 
}