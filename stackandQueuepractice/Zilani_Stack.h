#include<bits/stdc++.h>
using namespace std;
/////////////////////////////normal node////////////
template <typename n>
class Node{
public:
    n value;
    Node*Next;
    Node*Prev;
    Node(n val){
    this->value=val;
    this->Next=NULL;
    this->Prev=NULL;
    }
};
template <typename st>
class Stack{
public:
    int  ctn;
Node<st>*head;
Node<st>*top;
  Stack(){
      ctn=0;
  head=NULL;
  top=NULL;
  }
/////////////////push/////
void push(st val){
    Node<st>*newNode=new Node<st>(val);
if(head==NULL){
    head=newNode;
    top=newNode;
    ctn++;
    return;
}
top->Next=newNode;
newNode->Prev=top;
top=newNode;
ctn++;
return;
}
//////////////////////pop//////////
st pop(){
    st chk;
if(head==NULL){
    cout<<"The stack is already empty";
   // return chk;
}
if(head==top){

    chk=head->value;
    head=NULL;
    top=head;
    ctn--;
    return chk;
}
Node<st>*delNode=top;
chk=top->value;
top=delNode->Prev;
top->Next=NULL;
ctn--;
delete delNode;
return chk;
}
///////////////////////length////////
int length(){
return ctn;
}
///////////////////////empty/
bool empty(){
if(head==NULL)
    {return true;};
return false;
}
///////////top?//
st Top(){
    if(head!=NULL){
    return top->value;
    }
return top->value;
}
};
