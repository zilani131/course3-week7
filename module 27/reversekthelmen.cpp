#include<bits/stdc++.h>
using namespace std;
void reverseKthElement(queue<int>&q,int s,int k){
int l=s/k;
int re=s%k;
stack <int> st;
for(int i=0;i<l;i++){
    for(int j=0;j<k;j++){
        st.push(q.front());
        q.pop();
    }
      for(int j=0;j<k;j++){
        q.push(st.top());
        st.pop();
    }
}
 for(int j=0;j<re;j++){
        st.push(q.front());
        q.pop();
    }
      for(int j=0;j<re;j++){
        q.push(st.top());
        st.pop();
    }

}
int main(){
int n;
cin>>n;
//copying size to pass as parameter
int y=n;
int k;
cin>>k;
if(k==0||n==0){
    cout<<"Not possible"<<endl;
    return 0;
}
queue <int>z;
int val;
while(n--){
        cin>>val;
    z.push(val);
}
reverseKthElement(z,y,k);
while(!z.empty()){
    cout<<z.front()<<" ";
    z.pop();
}
}
//here if k=0 then it is not possible
//if size of queue < k then it will reverse every element
//if k<0 then it will give the same output as inserted in queue
//if the queue size is zero then it is not possible
