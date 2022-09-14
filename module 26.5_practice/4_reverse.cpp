#include<bits/stdc++.h>
//#include"MyQueue.h"
//#include"MyStack.h"

using namespace std;
void Print(queue<int>&q)
{
    while(!q.empty())
    {

        cout<<q.front()<<" ";
        q.pop();
    }
}
void reverse(queue<int> &q)
{
    stack <int> st;
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

}

int main()
{
    queue <int>q;
    int k;
    cin>>k;
    int val;
    while(k--)
    {
        cin>>val;
        q.push(val);
    }
    reverse(q);
    Print(q);
}
