#include<bits/stdc++.h>
#include"MyQueue.h"
using namespace std;
int main(){

Queue q;
q.push(2);
q.push(3);
q.push(5);
cout<<q.Front()<<" "<<q.Rear()<<endl;

while(!q.empty()){
    cout<<q.pop()<<endl;
}
}
