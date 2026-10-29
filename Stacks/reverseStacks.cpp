#include<iostream>
#include<stack> // stack is truly unlimited like LL
using namespace std;
void reverse (stack<int> &st){
stack<int> helper;
stack<int> helper1;
 cout<<"before reverse: ";
while (st.size()>0){
    cout<< st.top()<<" ";
    helper.push(st.top());
    st.pop();
}
cout<<endl;
// put back elem from helper to helper1;
while ((helper.size()>0)){
   helper1.push(helper.top());
   helper.pop(); 
}
// put helper1 elem to st == which is in a reverrse order
while(helper1.size()>0){
    st.push(helper1.top());
    helper1.pop();
}
cout<<"after reverse: ";
while(st.size()> 0){
    cout<<st.top()<<" ";
    st.pop();
}
 cout<<endl;
}
// void printBottomToTop(stack<int> &st){
// stack<int> helper;
// while (st.size()>0){
//     helper.push(st.top());
//     st.pop();
// }
// // put back elem from helper to st;
//  while ((helper.size()>0)){
//    /// helper me elem bottom to top hai to isko print kara 
//    cout<<helper.top()<<" ";
//    st.push(helper.top());
//    helper.pop(); 
// }
// cout<<endl;

// }
int main(){
    stack<int> st;
    st.push(10);// add top 
    st.push(20);
    st.push(30);
    st.push(40);
    reverse(st);
    //printTopToBottom(st);
    //printBottomToTop(st);
    
 
}