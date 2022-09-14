#include<bits/stdc++.h>
using namespace std;
template <typename t>
class Node
{
public:
    t value;
    Node* Next;
    Node* Prev;
    Node(t val)
    {
        value=val;
    }

};
template <typename st>
class Stack
{
public:
    Node<st>*head;
    Node<st>*top;
    int ctn;
public:
    Stack()
    {
        head=NULL;
        top=NULL;
        ctn=0;

    }
//////////////////push operation
    void push(st val)
    {
        Node<st>* newNode=new Node<st>(val);
        if(head==NULL)
        {
            head=top=newNode;
            ctn++;
            return;
        }
        top->Next=newNode;
        newNode->Prev=top;
        top=newNode;
        ctn++;
        return;
    }
//////////////////////////pop operation /////////////////////
    void pop()
    {
        st val;
        Node<st>*delNode;

        if(head==NULL)
        {
            return val; ////the stack is underflow
        }
        delNode=top;
        if(head==top)
        {
            head=top=NULL;

        }
        else
        {
            top=delNode->Prev;
            top->Next=NULL;

        }
        val=delNode->value;
        delete delNode;
        ctn--;
      //  return val;
    }
/////////////////////////status checking
    bool empty()
    {
        if(head==NULL)
        {
            return true;
        }
        return false;
    }
//////////////////size///////////
    int size()
    {
        return ctn;
    }
////////////////////////////top/////
    st Top()
    {
        st val;
        if(head==NULL)
        {
            cout<<"Stack underflow";
        }
        else
        {
            val=top->value;
        }
        return val;
    }
    st mid()
    {
        //cout<<ctn<<"coutnt"<<endl;
        if(ctn%2==1)
        {
            int k=ctn/2+1;
            int t=0;
            Node<st>*temp=head;
            while(t<k-1)
            {
                temp=temp->Next;
                t++;
            }
            return temp->value;
        }
        if(ctn%2==0)
        {
            int k=ctn/2;
            int t=0;
            Node<st>*temp=head;
            while(t<k-1)
            {
                temp=temp->Next;
                t++;
            }
            return temp->value;
        }
    }
};
