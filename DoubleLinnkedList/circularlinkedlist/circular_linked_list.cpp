#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node * next;
    Node(int input_data,Node * n){
        data=input_data;
        next=n;
    }
    Node(int input_data){
        data=input_data;
        next=nullptr;
    }
};
Node * convertcircularLL(vector<int> arr){
    Node * head=new Node (arr[0]);
    Node * mover=head;
    for(int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    // mover->next=head;
}
void print(Node * head){
    Node * temp=head;
    // cout<<temp->data<<" ";
    // temp=temp->next;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main (){
    vector<int> arr={1,2,3,4,5,6,7,8};
    Node * head=convertcircularLL(arr);
    print(head);
    return 0;
}