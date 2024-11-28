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
Node * convert_arr_ll(vector<int> arr){
    Node * head=new Node (arr[0]);
    Node * mover=head;
    for(int i=1;i<arr.size();i++){
        Node * temp=new Node (arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void displayLL(Node * head){
    Node * temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node * insertathead(Node * head,int val){
    Node *temp=new Node (val,head);
    return temp;
}
Node * insertatTail(Node * head,int val){
    if(head==nullptr){
        return new Node(val);
    }
    Node *temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node *newNode=new Node(val);
    temp->next=newNode;
    return head;
}
Node * insertatIndex(Node * head,int k ,int val){
    if(head==nullptr){
        return new Node(val);
    }
    if(k==1){
        Node * temp=new Node (val);
        temp->next=head;
        return temp;
    }
    Node * temp=head;
    Node * prev=nullptr;
    int count=0;
    while(temp!=nullptr){
        count++;
        if(count==(k-1)){
            Node * x=new Node (val);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node * insertatValueMatching(Node * head,int newval,int val){
    if(head==nullptr){
        return nullptr;
    }
    if(head->data==val){
        Node * temp=new Node (newval);
        temp->next=head;
        return temp;
    }
    Node * temp=head;
    while(temp!=nullptr){
        if(temp->next->data==val){
            Node * x=new Node (newval);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}
int main (){
    vector<int> arr={1,2,3,4,55,6,7,8,9};
    Node * head=convert_arr_ll(arr);
    displayLL(head);
    cout<<endl;
    // head=insertathead(head,100);
    // displayLL(head);
    // head=insertatTail(head,1000);
    // displayLL(head);
    // head=insertatIndex(head,10,100 );
    // displayLL(head);
    head=insertatValueMatching(head,999,55);
    displayLL(head);
    return 0;
}