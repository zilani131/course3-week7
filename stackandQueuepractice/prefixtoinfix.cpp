#include<bits/stdc++.h>
#include"Zilani_Stack.h"
using namespace std;
int precisionCalc(char s){

if(s=='^'){
    return 3;
}
else if(s=='/'||s=='*'){
    return 2;
}
else if(s=='+'||s=='-'){
    return 1;
}
 return -1;
}

string infixToPrefix(string chk){
Stack <char>st;
cout<<chk.length()<<endl;
reverse(chk.begin(),chk.end());
string result;
for(int i=0;i<chk.length();i++){
    if(chk[i]>='0'&&chk[i]<='9'){
        result+=chk[i];
    }
    else if(chk[i]==')'){

            st.push(chk[i]);
            //cout<<"zilani"<<st.Top()<<endl;


    }
    else if(chk[i]=='('){
                /////////////////must check the top !=')'
                while(!st.empty()&&st.Top()!=')'){
                    result+=st.pop();
                    //cout<<result<<"Inside"<<endl;
                    //st.pop();
                }
                st.pop();
            }
        else{
            if(precisionCalc(chk[i])>precisionCalc(st.Top()))
            {

                st.push(chk[i]);
               // cout<<"zilani1"<<st.Top()<<endl;
            }
            else{
                 while(!st.empty()&&precisionCalc(st.Top())>=precisionCalc(chk[i])){
                    result+=st.Top();
                    st.pop();
                }
                st.push(chk[i]);
               // cout<<"zilani2"<<st.Top()<<endl;
            }
        }
      //  cout<<result<<" iteration "<<i<<endl;
}
while(!st.empty()){
    result+=st.Top();
    st.pop();
}
reverse(result.begin(),result.end());
return result;
}


//////////////////////string infix to post fix//////
string infixTopostFix(string chk){
    Stack<char>st;
    string result;
for(int i=0;i<chk.length();i++)
{
    if(chk[i]>='0'&&chk[i]<='9'){
       result+=chk[i];
    }
    else if(chk[i]=='('){
                st.push(chk[i]);
            }
    else if(chk[i]==')'){
        while(!st.empty()&&st.Top()!='('){
                result+=st.pop();
              }
              st.pop();
    }
    else {
        if(precisionCalc(chk[i])>precisionCalc(st.Top())){
          st.push(chk[i]);
        }
        else{
            while(!st.empty()&&precisionCalc(chk[i])>precisionCalc(st.Top()))
            {
                result+=st.pop();
            }

        }
    }

}
while(!st.empty())
            {
                result+=st.pop();
            }
        return result;
}
int prefixEvolution(string chk){
Stack<int>it;
for(int i=chk.length()-1;i>=0;i--){
    if(chk[i]>='0'&&chk[i]<='9'){
        it.push(chk[i]-'0');
    }
    else{
        int a=it.pop();
        int b=it.pop();
        switch (chk[i]){
    case '+':
        it.push(a+b);
        break;
    case '-':
        it.push(a-b);
        break;
    case '*':
        it.push(a*b);
        break;
    case '/':
        it.push(a/b);
        break;
    case '^':
        it.push(pow(a,b));
        break;

        }
    }
}
return it.Top();

}
int postfixEvolution(string chk){
Stack<int>it;
for(int i=0;i<chk.length();i++){
    if(chk[i]>='0'&&chk[i]<='9'){
        it.push(chk[i]-'0');
    }
    else{
        int a=it.pop();
        int b=it.pop();
        switch (chk[i]){
    case '+':
        it.push(a+b);
        break;
    case '-':
        it.push(a-b);
        break;
    case '*':
        it.push(a*b);
        break;
    case '/':
        it.push(a/b);
        break;
    case '^':
        it.push(pow(a,b));
        break;

        }
    }
}
return it.Top();

}
int main(){
string c="(3+(2*3)*(4*5))";
string s=infixToPrefix(c);
string po=infixTopostFix(c);
cout<<po<<" "<<postfixEvolution(po)<<endl;
cout<<prefixEvolution(s);

}
