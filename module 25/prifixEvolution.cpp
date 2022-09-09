#include<bits/stdc++.h>
#include"MyStack.h"
using namespace std;
int precisionCalc(char s)
{
    if(s=='^')
    {
        return 3;
    }
    else if(s=='*'||s=='/')
    {
        return 2;
    }
    else if(s=='+'||s=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infixToPrifix(string chk)
{
    Stack<char> st;
    reverse(chk.begin(),chk.end());
    cout<<chk<<endl;
    string result;
    cout<<result<<endl;
    for(int i=0; i<chk.length(); i++)
    {
        if(chk[i]>='0'&&chk[i]<='9')
        {
            result+=chk[i];
        }
        else if(chk[i]==')')
        {

            st.push(chk[i]);
        }
        else if(chk[i]=='(')
        {
            //st.empty() it is used to senati check if the last value is empty and to avoid it,we used it
            while(!st.empty()&&st.Top()!=')')
            {
                result+= st.pop();
            }
            if(!st.empty())
            {
                //  cout<<result<<"before"<<endl;
                st.pop();
                // cout<<result<<"before"<<endl;
            } //here we pop the ')' and clear the stack
        }
        else
        {
            // cout<<precisionCalc(st.Top())<<" "<<precisionCalc(chk[i])<<endl;
            while(!st.empty()&&precisionCalc(st.Top())>=precisionCalc(chk[i]))
            {
                result+=st.pop();
            }
            st.push(chk[i]);
        }
    }
    while(!st.empty())
    {
        result+=st.pop(); /////we pop until the last value
    }
    // cout<<result<<endl;
    reverse(result.begin(),result.end());
    return result;
}
string infixTopostFix(string chk)
{
    Stack<char> st;
    string result;
    for(int i=0; i<chk.length(); i++)
    {
        if(chk[i]>='0'&&chk[i]<='9')
        {
            result+=chk[i];
        }
        else if(chk[i]=='(')
        {
            st.push(chk[i]);
        }
        else if(chk[i]==')'){
            while(!st.empty()&&st.Top()!='('){
                    result+=st.pop();
                  }
            if(!st.empty())st.pop();
        }
        else{
            while(!st.empty()&&precisionCalc(st.Top())>=precisionCalc(chk[i])){
                result+=st.pop();
            }
            st.push(chk[i]);
        }
    }
   while(!st.empty()){
    result+=st.pop();
   }
   return result;
}

int prefixEvolution(string chk)
{
    Stack<int> st;
    for(int i=chk.length()-1; i>=0; i--)
    {
        if(chk[i]>='0'&&chk[i]<='9')
        {
            //we have to send integer so we converted the character into integer
            st.push(chk[i]-'0');
        }
        else
        {
            int a=st.pop();
            int b=st.pop();
            cout<<a<<" "<<b<<endl;
            switch(chk[i])
            {
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
int postfixEvolution(string chk)
{
    Stack <int> st;
    for(int i=0; i<chk.length(); i++)
    {
        if(chk[i]>='0'&&chk[i]<='9')
        {
            st.push(chk[i]-'0');
        }
        else
        {
            int b=st.pop();
            int a=st.pop();//must be care full in '-' and '/'
            cout<<a<<" "<<b<<endl;
            switch(chk[i])
            {
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
int main()
{
    string chk="(7+(4*5))-(2+0)";
    cout<<infixTopostFix(chk)<<endl;

    cout<<prefixEvolution(infixToPrifix(chk))<<endl;
    // cout<<prefixEvolution("-+7*45+20");
    cout<<postfixEvolution(infixTopostFix(chk));

}
