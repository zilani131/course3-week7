#include<bits/stdc++.h>
#include"MyQueue.h"
using namespace std;
///////////////////////q in////////////////////
Queue<int> qIn(){
Queue <int> qt;
int n;
cin>>n;
while(n--){
        int val;
cin>>val;
    qt.push(val);
}
return qt;
}

int main(){

Queue<int> m=qIn();
int k;
cin>>k;
int a[k];
for(int i=0;i<k;i++){
    cin>>a[i];

}
//cout<<"main"<<endl;
for(int i=0;i<k;i++){

    cout<<m.findFreq(a[i])<<endl;
}

}
