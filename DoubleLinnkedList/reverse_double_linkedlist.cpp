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
void revPrint(Node * head){
    Node * last=head;
    while(last->next!=nullptr){
        last=last->next;
    }
    while(last!=nullptr){
        cout<<last->data<<" ";
        last=last->back;
    }
}
// void reverse(Node * head){
//     Node *first=head;
//     Node * last=head;
//     int count=0;
//     while(last->next!=nullptr){
//         count++;
//         last=last->next;
//     }
//     while(count!=(count/2)){
//         int temp=first->data;
//         first->data=last->data;
//         last->data=temp;
//         first=first->next;
//         last=last->back;
//     }
// }
void reversethroughstack(Node * head){
    stack<int> s;
    Node * temp=head;
    while(temp!=nullptr){
        s.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        temp->data=s.top();
        s.pop();
        temp=temp->next;
    }
}
int main (){
    vector<int> arr={5,6,7,8};
    Node * head=convertLL(arr);
    print(head);
    cout<<endl;
    // revPrint(head);
    // reverse(head);
    // print(head);
    reversethroughstack(head);
    print(head);
    return 0;
}