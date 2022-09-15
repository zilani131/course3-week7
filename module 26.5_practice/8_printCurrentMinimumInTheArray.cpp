#include<bits/stdc++.h>
using namespace std;
void PrintCurrentMin(int a[],int n){
stack<int>st;
st.push(a[0]);
for(int i=1;i<n;i++){
        if(a[i]<=st.top()){
            st.push(a[i]);
        }
}
for(int i=n-1;i>=0;i--){
    if(a[i]!=st.top()){
        while(a[i]!=st.top()){
            cout<<st.top()<<" ";
            i--;
        }
        cout<<st.top()<<" ";
        st.pop();
    }
    else{
        cout<<st.top()<<" ";
        st.pop();
    }
}

}
int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}

PrintCurrentMin(a,n);

}
