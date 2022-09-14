#include<bits/stdc++.h>
using namespace std;
template <typename n>
class Node{
    public:
n value;
Node*Next;
Node(n val){
value=val;
Next=NULL;
}
};
template <typename q>
class Queue{
public:
    q ctn;
    Node<q>*front;
    Node<q>*rear;
    Queue(){
        ctn=0;
    front=NULL;
    front=NULL;
    }

////////////////////////push////////////
void push(int val){
    Node<q>*newNode=new Node<q>(val);
    if(front==NULL){

        front=newNode;
        rear=newNode;
        return;
    }
rear->Next=newNode;
rear=newNode;
return;
}
/////////
q pop(){
    q chk=front->value;
if(front==NULL){
    cout<<"Nothing to pop"<<endl;
    return chk;
}
//int chk=front->value;
else if(front ==rear){
        Node<q> *delNode=front;
    front =NULL;
    rear=NULL;
    delete delNode;
    return chk;

}
Node<q>*temp=front;
front=temp->Next;
delete temp;
return chk;
}
bool empty(){
if(front==NULL) return true ;
return false;
}
q Top(){
    q chk=front->value;
if(front ==NULL){
        cout<<"the queue is empty"<<endl;
    return chk ;
}
return chk;

}
};
