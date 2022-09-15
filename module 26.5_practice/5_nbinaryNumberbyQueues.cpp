#include<bits/stdc++.h>
using namespace std;
void binary_Number(queue<string>&q){
    string s1=q.front();
    q.pop();
    cout<<s1<<endl;
    string s2=s1;
    s1+="0";
    q.push(s1);
    s2+="1";
    q.push(s2);


}
int main(){
int n;
cin>>n;
queue <string> k;
k.push("1");
while(n--){
    binary_Number(k);
}



}
