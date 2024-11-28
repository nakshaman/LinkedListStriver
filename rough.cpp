#include <bits/stdc++.h>
using namespace std;
class Node{
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

Node *convertLL(vector<int> arr){
    Node * head=new Node(arr[0]);
    Node * mover=head;
    for(int i=1;i<arr.size();i++){
        Node * temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
int search(Node * head,int value){
    Node * temp=head;
    while(temp!=nullptr){
        if(value==temp->data){
            return 1;
        }
        else{
            temp=temp->next;
        }
    }
    return 0;
}
int countLength(Node * head){
    int count=0;
    Node * temp=head;
    while(temp!=0){
        count++;
        temp=temp->next;
    }
    return count;
}
Node * deleteHead(Node * head){
    if(head==NULL){
        return head;
    }
    Node *temp=head;
    head=head->next;
    free(temp); // delete temp
    return head;
}
Node *displayLinkedList(Node * head){
    Node * temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main (){
    vector<int> arr={1,2,3,4,5,6,7,8};
    Node * head=convertLL(arr);
    cout<<endl;
    displayLinkedList(head);
    cout<<"Element is found "<<search(head,7)<<endl;
    cout<<"The length of the Linked list is "<<countLength (head)<<endl;
    head=deleteHead(head);
    displayLinkedList(head);
    return 0;
}