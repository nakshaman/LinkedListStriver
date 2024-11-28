#include <bits/stdc++.h>
using namespace std;
class Node{
    public:

    int data;
    Node * next;
    Node * back;
    public:

    Node(int input_data,Node * newNext,Node * newBack){
        data=input_data;
        next=newNext;
        back=newBack;
    }
    Node(int input_data){
        data=input_data;
        next=nullptr;
        back=nullptr;
    }
};
Node * convert_arr_dll(vector<int> arr){
    Node * head=new Node(arr[0]);
    Node * prev= head;
    for(int i=1;i<arr.size();i++){
        Node * temp=new Node(arr[i],nullptr,prev);
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
Node* deleteHead(Node * head){
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    Node * temp=head;
    head=head->next;
    temp->next=nullptr;
    head->back=nullptr;
    free(temp);
    return head;
}
Node * deleteTail(Node * head){
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    Node * temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    Node * last=temp->next;
    temp->next=nullptr;
    last->back=nullptr;
    delete last;
    return head;

}
Node * deleteAtIndex(Node * head,int k){
    if(head==nullptr){
        return nullptr;
    }
    int count=0;
    Node * temp =head;
    while(temp!=nullptr){
        count++;
        if(count==k){
            break;
        }
        temp=temp->next;
    }
    Node * prev=temp->back;
    Node * front=temp->next;
    if(prev==nullptr && front==nullptr){
        delete temp;
        return nullptr;
    }
    else if(prev==nullptr){
        return deleteHead(head);
    }
    else if(front==nullptr){
        return deleteTail(head);
    }
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return head;
}
Node * specificElement(Node * head,int val){
    if(head->data==val){
        cout<<"You can not delete the Head of the Linked List"<<endl;
        return NULL;
    }
    Node * temp =head;
    while(temp!=nullptr){
        if(temp->data==val){
            break;
        }
        temp=temp->next;
    }
    Node * prev=temp->back;
    Node * front=temp->next;
    if(prev==nullptr && front==nullptr){
        delete temp;
        return nullptr;
    }
    else if(prev==nullptr){
        cout<<"You can not delete the Head of the Linked List"<<endl;
        return NULL;
    }
    else if(front==nullptr){
        return deleteTail(head);
    }
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return head;
}
int main (){
    vector<int> arr={9,8,7,6,5,4,3};
    Node* head=convert_arr_dll(arr);
    print(head);
    cout<<endl;
    // head=deleteHead(head);
    // print(head);
    // head=deleteTail(head);
    // print(head);
    // head=deleteAtIndex(head,5);
    // print(head);
    // head=specificElement(head,9);
    // print(head);
    return 0;
}