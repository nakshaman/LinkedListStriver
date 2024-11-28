#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node * back;
    Node(int input_data,Node * n,Node * b){
        data=input_data;
        next=n;
        back=b;
    }
    Node(int input_data){
        data=input_data;
        next=nullptr;
        back=nullptr;
    }
};
Node * convert(vector<int> arr){
    Node * head=new Node(arr[0]);
    Node * prev=head;
    for(int i=1;i<arr.size();i++){
        Node * temp=new Node(arr[i],nullptr,head);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
void print(Node * head){
    Node * temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node *sumLL(Node *head1,Node * head2){
    Node *temp1=head1;
    Node *temp2=head2;
    Node *dummyNode=new Node(-1);
    Node * current=dummyNode;
    int carry=0;
    int sum=0;
    while(temp1!=nullptr || temp2!=nullptr){
        sum=carry;
        if(temp1){
            sum+=temp1->data;
        }
        if(temp2){
            sum+=temp2->data;
        }
        Node * newNode=new Node(sum%10);
        carry=sum/10; 
        current->next=newNode;
        current=current->next;
        if(temp1){
            temp1=temp1->next;
        }
        if(temp2){
            temp2=temp2->next;
        }
    }
    if(carry){
        Node *newNode=new Node(carry);
        current->next=newNode;
    }
    return dummyNode->next;
}
int main (){
    vector<int>arr1={3,5};
    vector<int>arr2={4,5,9,9};
    Node * head1=convert(arr1);
    Node * head2=convert(arr2);
    print(head1);
    print(head2);
    Node * dummyhead=sumLL(head1,head2);
    print(dummyhead);
    return 0;
}