#include<bits/stdc++.h>
#include"MyStack.h"
using namespace std;
int prefixEvolution(string chk){
    Stack<int> st;
for(int i=chk.length()-1;i>=0;i--){
    if(chk[i]>='0'&&chk[i]<='9'){
            //we have to send integer so we converted the character into integer
        st.push(chk[i]-'0');
    }
    else{
            int a=st.pop();
             int b=st.pop();
        switch(chk[i]){
    case '+':
        st.push(a+b);
        break;
    case '-':
        st.push(a-b);
        break;
    case '*':
        st.push(a*b);
        break;
    case '/':
        st.push(a/b);
        break;
    case '^':
        st.push(pow(a,b));
        break;
        }
    }

}

return st.Top();

}
int main(){
cout<<prefixEvolution("+*423")<<endl;
cout<<prefixEvolution("-+7*45+20");

}
