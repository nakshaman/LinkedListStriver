#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node * next;
    Node * back;
    Node(int input_data,Node * next1,Node * back1){
        data=input_data;
        next=next1;
        back=back1;
    }
    Node(int input_data){
        data=input_data;
        next=nullptr;
        back=nullptr;
    }
};
Node * convertLL(vector<int> arr){
    Node * head=new Node (arr[0]);
    Node * prev=head;
    for(int i=1;i<arr.size();i++){
        Node * temp=new Node (arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
void print(Node * head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}
Node * insertHead2LL(Node * head,int val){
    Node * temp=new Node(val,head,nullptr);
    temp->back=nullptr;
    head->back=temp;
    return temp;
}
Node * insertTail2LL(Node * head,int val){
    if(head->next==nullptr){
        return insertHead2LL(head,val);
    }
    Node * last=head;
    while(last->next->next!=nullptr){
        last=last->next;
    }
    Node * front=last->next;
    Node * newNode=new Node(val,front,last);
    last->next=newNode;
    front->back=newNode;
    return head;
}
Node * insertatLast(Node * head,int val){
    Node * temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node * newNode=new Node (val,nullptr,temp);
    temp->next=newNode;
    return head;
}
Node * insertAtindex(Node * head,int k,int val){
    if(head==nullptr){
        return new Node(val);
    }
    if(k==1){
        return insertHead2LL(head,val);
    }
    Node * temp=head;
    int count=0;
    while(temp!=nullptr){
        count++;
        if(count==k) break;
        temp=temp->next;
    }
    if(temp->next==nullptr){
        return insertatLast(head,val);
    }
    Node * prev=temp->back;
    Node * newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;
}
void insertBeforeNode(Node * node,int val){
    Node * prev=node->back;
    Node * newNode=new Node (val,node,prev);
    prev->next=newNode;
    node->back=newNode;
}
int main (){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    Node * head=convertLL(arr);
    print(head);
    cout<<endl;
    // head=insertHead2LL(head,99);
    // print(head);
    // head=insertTail2LL(head,1001);
    // print(head);
    // head=insertAtindex(head,11,0);
    // print(head);
    insertBeforeNode(head->next->next,480);
    print(head);
    return 0;
}