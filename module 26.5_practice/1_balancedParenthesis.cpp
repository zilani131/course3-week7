#include<bits/stdc++.h>
#include"MyStack.h"
using namespace std;

bool balancedParenthesis(string chk){
Stack <char> st;

//// corner case like ](()) here ending tag come first so not balanced
if(chk[0]=='}'||chk[0]==')'||chk[0]==']'){
    return false;
}

for(int i=0;i<chk.length();i++){
    if(chk[i]=='{'||chk[i]=='('||chk[i]=='['){
        st.push(chk[i]);
       }

       else if(chk[i]==')'){
           if(st.Top()!='('){
                return false;
              }
              else{
                st.pop();
              }
        }
            else if(chk[i]=='}'){
           if(st.Top()!='{'){
                return false;
              }
              else{
                st.pop();
              }
        }
            else if(chk[i]==']'){
           if(st.Top()!='['){
                return false;
              }
              else{
                st.pop();
              }
        }



}

//for corner case like  [{()
if(st.empty()){
    return true;
}
else {
    return false;
}

}

int main()
{
    string chk;
    cin>>chk;

    if (balancedParenthesis(chk))
    {

    cout<<"YES";}
    else{
        cout<<"NO";
    }

}
