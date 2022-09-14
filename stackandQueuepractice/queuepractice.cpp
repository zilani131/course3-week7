#include<bits/stdc++.h>
#include"Zilani_Queue.h"
using namespace std;
int main(){

Queue <char>q;
q.push('a');
q.push('b');
cout<<q.Top()<<endl;
while(!q.empty()){
    cout<<q.pop()<<" ";
}
}
