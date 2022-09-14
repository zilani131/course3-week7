#include<bits/stdc++.h>
#include"Zilani_Stack.h"
using namespace std;
int main(){
Stack<int> st;
st.push(2);
st.push(3);
cout<<st.length()<<endl;
cout<<st.empty()<<endl;
while(!st.empty()){

    cout<<st.Top()<<" "<<!st.empty()<<endl;
    st.pop();

}
cout<<!st.empty()<<endl;


}
