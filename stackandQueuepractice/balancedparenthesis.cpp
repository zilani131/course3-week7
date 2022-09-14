#include<bits/stdc++.h>
#include"Zilani_Stack.h"
using namespace std;
bool balancedParenthesis(string s){
    Stack <char>st;
    if(s[0]==')'||s[0]=='}'||s[0]==']'){
        return false;
    }
for(int i=0;i<s.length();i++){
    if(s[i]=='('||s[i]=='{'||s[i]=='['){
        st.push(s[i]);
       }
    else{

        if(s[i]==')'&&st.Top()=='('){
            st.pop();
        }

       else if(s[i]=='}'&&st.Top()=='{'){
            st.pop();
        }

       else if(s[i]==']'&&st.Top()=='['){
            st.pop();
        }
        else{
            return false;
        }
    }
}
if(!st.empty()){
    return false ;

}
return true;

}
int main(){
string a;
cin>>a;
if(balancedParenthesis(a)){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO";
}
}
