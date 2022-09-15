#include<bits/stdc++.h>
using namespace std;
string reverseEachWordSeparetdByDot(string &q){
stack <char>st;
string result;
for(int i=0;i<q.length();i++){
   if(q[i]!='.'){
    st.push(q[i]);
   }

    else if(q[i]=='.'){
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        result+=q[i];

    }
}
while(!st.empty()){
    result+=st.top();
    st.pop();
}
return result;

}

int main(){
string s;
cin>>s;
string re=reverseEachWordSeparetdByDot(s);
cout<<re;

}
