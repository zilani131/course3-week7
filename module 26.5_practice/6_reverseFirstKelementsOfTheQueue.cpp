#include<bits/stdc++.h>
using namespace std;
void reverseFirstKElement(queue<int>&q,int t,int k){
    stack <int>st;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
while(!st.empty()){
    q.push(st.top());
    st.pop();
}
for(int i=0;i<t-k;i++){
    q.push(q.front());
        q.pop();
}
}

int main(){
int s,w;
cin>>s;
int siz=s;
cin>>w;
//corner case
if(s<w||s==0||w<0){
        cout<<"Not possible"<<endl;
    return 0;
}
int val;
queue <int> z;
while(s--){
    cin>>val;
    z.push(val);

}
reverseFirstKElement(z,siz,w);
while(!z.empty()){
    cout<<z.front()<<" ";

    z.pop();
}

}
