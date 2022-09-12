#include<bits/stdc++.h>
#include"MyStack.h"
using namespace std;
int precisionCalc(char a)
{
    if(a=='^')
    {
        return 3;
    }
    else if(a=='*'||a=='/')
    {
        return 2;
    }
    else if(a=='+'||a=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }

}
string infixToPrefix(string chk)
{

    Stack<char> st;
    string result;
    reverse(chk.begin(),chk.end());
    cout<<chk<<endl;
    for(int i=0; i<chk.length(); i++)
    {    cout<<result<<endl;
        if(chk[i]>='0'&&chk[i]<='9')
        {
            result+=chk[i];
            cout<<result<<" Num"<<endl;
          //  cout<<"number"<<result<<endl;
        }
        else if(chk[i]==')')
        {
            st.push(chk[i]);
             cout<<st.Top()<<"Top"<<endl;
        }
        else if(chk[i]=='(')
        {

            while(!st.empty()&&st.Top()!=')')
            {   cout<<st.Top()<<"Top"<<endl;
                result+=st.pop();
                cout<<result<<" ("<<endl;
                 cout<<st.Top()<<"Top"<<endl;
                //cout<<result<<"Afterpop"<<endl;
            }
            cout<<st.Top()<<"top"<<endl;
            if(!st.empty())
            {
                cout<<st.pop()<<"aaa"<<endl;}
        }

        else
        { cout<<precisionCalc(st.Top())<<st.Top()<<" "<<precisionCalc(chk[i])<<chk[i]<<endl;
            while(!st.empty()&&precisionCalc(st.Top())>=precisionCalc(chk[i]))
            {
                result+=st.pop();
                cout<<result<<"preci"<<endl;
            }
            st.push(chk[i]);
        }


    }

    while(!st.empty())
    {
        result+=st.pop();
    }
    reverse(result.begin(),result.end());
    return result;

}
int prefixEvolution(string chk)
{
    Stack <int>st;
    for(int i=chk.length()-1; i>=0; i--)
    {
        if(chk[i]>='0'&&chk[i]<='9')
        {
            st.push(chk[i]-'0');
        }
        else
        {
            int a=st.pop();
            int b=st.pop();
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

//cout<<prefixEvolution("+9*3/84");
    cout<<infixToPrefix("9+3*(8/4)");
}
