#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int input_data,Node *n){
        data=input_data;
        next=n;
    }
    Node(int input_data){
        data=input_data;
        next=nullptr;
    }
};
Node * convert(vector<int> arr){
    Node * head=new Node(arr[0]);
    Node * mover=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
int search(Node * head,int val){
    Node * temp=head;
    while(temp!=nullptr){
        if(temp->data==val){
            return 1;
        }
        else{
            temp=temp->next;
        }
    }
    return 0;
}
void print(Node *head){
    Node * temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main (){
    vector<int> arr={10,20,30,40,50};
    Node * head=convert(arr);
    print(head);
    int ans=search(head,40);
    cout<<ans<<endl;
    return 0;
}