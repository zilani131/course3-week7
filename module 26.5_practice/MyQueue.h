#include<bits/stdc++.h>
using namespace std;
template <typename n>
class Node{
public:
n value;
Node *Next;
public:
    Node(n val){
    this->value=val;
    Next=NULL;
    }
};
template <typename q>
class Queue{
Node<q> *front;
Node<q> *rear;
public:
    Queue(){
    front=NULL;
    rear=NULL;
    }

void push(q val){
Node<q> *newNode=new Node<q>(val);
if(front==NULL){
    front=newNode;
    rear=newNode;
    return;
}
rear->Next=newNode;
rear=rear->Next;
return;
}

///////////////////////////pop///////////////////
q pop(){
    q chk;
if(front==NULL){
        cout<<"the queue is underflow | There is no value in the queue"<<endl;
    return chk;
}
Node<q> *delNode=front;
front=front->Next;
if(front==NULL){
    rear=NULL;
}
chk=delNode->value;
delete delNode;
return chk;

}
/////////////////////////////////////////empty/////////
bool empty(){
if(front==NULL)return true;
return false;
}
//////////////////////////
q Front(){
if(front==NULL){
    return -1;
}
return front->value;
}
//////////////////////////rear///////////
q Rear(){
if(front==NULL){
    return -1;
}
return rear->value;
}
int findFreq(q val){
Node <q>*temp=front;
int s=0;
while(temp!=NULL){
        //cout<<"out"<<endl;
    if(temp->value==val){
       // cout<<temp->value<<"q"<<endl;
        s++;
    }
temp=temp->Next;
}
if(s==0){
    return -1;
}
return s;
}
};
