#include<iostream>
#include<stack> // stack is truly unlimited like LL
using namespace std;
int main(){
    stack<int> st;
    st.push(10);// add top 
    st.push(20);
    st.push(30);
    st.push(40);
    st.pop(); //remove top
    cout<<st.top()<<endl;
    cout<<st.size();
}