#include<bits/stdc++.h>
#include"Zilani_Queue.h"
using namespace std;
int find(Queue<int> &st,int k)
{
Node<int>*temp=st.front;
int sum=0;
while(temp!=NULL){
   if(temp->value==k){
    sum++;
   }
  temp=temp->Next;
}
  if(sum!=0){
    return sum;
  }
  return -1;

}
int main(){
Queue<int> q;
int n;
cin>>n;
int val;
while(n--){

cin>>val;
q.push(val);
}
int m;
cin>>m;
int a[m];
for(int i=0;i<m;i++){
   cin>>a[i];
}
for(int i=0;i<m;i++){
   cout<<find(q,a[i])<<endl;
}



}
