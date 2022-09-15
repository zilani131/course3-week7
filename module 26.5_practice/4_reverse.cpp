#include<bits/stdc++.h>
using namespace std;
stack<int>reverseStack(stack <int>&k){
stack <int> z;
while(!k.empty()){
    z.push(k.top());
    k.pop();
}

return z;
}
stack<int> sortQueue(stack<int>&k){
//cout<<k.top();
stack <int>tq;
int  temp;
int z;
while(!k.empty()){
    temp=k.top();
    //cout<<temp<<"first temp"<<endl;
    k.pop();
   // cout<<tq.empty()
    if(tq.empty()){
        tq.push(temp);
      //  cout<<tq.top()<<"tq temp"<<endl;
    }
    else{
            //if equal or greater then push
         if(temp>=tq.top()){
        tq.push(temp);
    }
    else{
            //we have to give the sanaty check
        while(!tq.empty()&&temp<tq.top()){
            z=tq.top();
            tq.pop();
            k.push(z);
        }
        tq.push(temp);
    }
    }



}

return reverseStack(tq);

}
int main(){
int n;
cin>>n;
stack <int>q;
int val;
while(n--)
{
    cin>>val;
q.push(val);

}
stack <int> s;
s=sortQueue(q);
while(!s.empty()){

    cout<<s.top()<<" ";
    s.pop();
}
}
