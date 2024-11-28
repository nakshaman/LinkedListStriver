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
Node * deleteHead(Node * head){
    if(head==nullptr){
        return nullptr;
    }
    Node *temp=head;
    head=head->next;
    delete temp;
    return head;
}
Node * deleteTail(Node * head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node * temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}
Node * deleteLink(Node * head,int k){
    if(head==nullptr){
        return head;
    }
    if(k==1){
        Node *temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int count=0;
    Node * temp=head;
    Node *prev=nullptr;
    while(temp!=nullptr){
        count++;
        if(count==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node * removeElement(Node * head,int element){
    if(head==nullptr) return nullptr;
    if(head->data==element){
        Node * temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node * temp=head;
    Node * prev=nullptr;
    while(temp!=nullptr){
        if(temp->data==element){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
int main (){
    // vector<int> arr={1,2,3,4,5,6,7,8,9,10,11,12};
    vector<int> arr={8,7,6,4,33,32,22,21};
    Node * head=convertLLarr(arr);
    displayLinkedList(head);
    cout<<endl;
    // head=deleteHead(head);
    // displayLinkedList(head);
    // head=deleteTail(head);
    // displayLinkedList(head);
    // head=deleteLink(head,10);
    // displayLinkedList(head);
    head=removeElement(head,33);
    displayLinkedList(head);
    return 0;
}