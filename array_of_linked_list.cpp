#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int input_data,Node *next_ptr){
        data=input_data;
        next=next_ptr;
    }
    public:
    Node(int input_data){
        data=input_data;
        next=nullptr;
    }
};
Node* convert_arr_linkedlist(vector<int> &arr){
    Node * head=new Node(arr[0]);
    Node * mover=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
int count_length(Node* head){
    int count=0;
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
        count++;
    }
    cout<<endl;
    return count;
}
int search(Node *head,int num){
    Node *temp=head;
    while(temp!=nullptr){
        if(num==temp->data){
            return 1;
        }
        else{
            temp=temp->next;
        }
    }
}
int main (){
    vector<int>arr={2,3,4,5,6};
    Node * head=convert_arr_linkedlist(arr);
    // Node*temp=head;
    // while(temp!=nullptr){
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }
    cout<<"The length of the linked list is "<<count_length(head)<<endl;
    int search_no;
    cout<<"enter the number you want to search in this linked list "<<endl;
    cin>>search_no;
    cout<<search(head,search_no)<<endl;
    return 0;
}