#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int value;
Node *Next;
public:
    Node(int val){
    this->value=val;
    Next=NULL;
    }
};

class Queue{
Node *front;
Node *rear;
public:
    Queue(){
    front=NULL;
    rear=NULL;
    }

void push(int val){
Node *newNode=new Node(val);
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
int pop(){
    int chk=-1;
if(front==NULL){
        cout<<"the queue is underflow | There is no value in the queue"<<endl;
    return chk;
}
Node *delNode=front;
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
int Front(){
if(front==NULL){
    return -1;
}
return front->value;
}
//////////////////////////rear///////////
int Rear(){
if(front==NULL){
    return -1;
}
return rear->value;
}
};
