#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int input_data,Node *ptr){
        data=input_data;
        next=ptr;
    }
    Node(int input_data){
        data=input_data;
        next=nullptr;
    }
};
void traverse(Node * head){
    Node *ptr=head;
    while(ptr->next!=head){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<ptr->data;
}
int main (){
    Node *head=new Node(1);
    Node *second=new Node(2);
    Node *third=new Node(3);
    Node *fourth=new Node(4);
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=head;
    traverse(head);
    return 0;
}