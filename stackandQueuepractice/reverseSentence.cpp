#include<bits/stdc++.h>
#include"Zilani_Stack.h"
using namespace std;
void reverseSentence(string chk){
Stack <string> st;
for(int i=0;i<chk.length();i++){
    string word="";
    while(i<chk.length()&&chk[i]!=' '){
    word+=chk[i];
    i++;
    }
    st.push(word);

}
while(!st.empty()){
    cout<<st.pop()<<" ";
}

}

int main()
{
    string z="zilani is a good boy";
    reverseSentence(z);
}
