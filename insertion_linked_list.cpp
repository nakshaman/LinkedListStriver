#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node * next;
    Node(int input_data,Node * ptr){
        data=input_data;
        next=ptr;
    }
    Node(int input_data){
        data=input_data;
        next=nullptr;
    }
};
Node * convertLLarr(vector<int> arr){
    Node * head=new Node (arr[0]);
    Node * mover=head;
    for(int i=1;i<arr.size();i++){
        Node * temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
Node *displayLinkedList(Node * head){
    Node * temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node * insertHead(Node * head,int value){
    Node * temp=new Node(value,head);
    return temp;
}
Node * insertTail(Node * head,int val){
    if(head==nullptr){
        return new Node (val);
    }
    Node * temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node * newNode=new Node(val);
    temp->next=newNode;
}
Node * insertatIndex(Node * head,int val,int k){
    if(head==nullptr){
        if(k==1){
            return new Node(val);
        }
        else{
            return head;
        }
    }
    if(k==1){
        return new Node(val,head);
    }
    int count=0;
    Node *temp=head;
    while(temp!=nullptr){
        count++;
        if(count==(k-1)){
            Node *x=new Node(val,temp->next);
            // x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}
Node * insertatElement(Node * head,int val,int newValue){
    if(head==nullptr){
        return nullptr;
    }
    if(head->data==val){
        return new Node(val,head);
    }
    Node *temp=head;
    while(temp->next!=nullptr){
        if(temp->next->data==val){
            Node *x=new Node(newValue,temp->next);
            // x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}
int main (){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    Node* head=convertLLarr(arr);
    displayLinkedList(head);
    cout<<endl;
    // head=insertHead(head,100);
    // displayLinkedList(head);
    // head=insertTail(head,66);
    // displayLinkedList(head);
    head=insertatIndex(head,100,1);
    displayLinkedList(head);
    // head=insertatElement(head,10,15);
    // displayLinkedList(head);
    return 0;
}

