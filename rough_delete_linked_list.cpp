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
Node * deleteHead(Node * head){
    if(head==nullptr) return nullptr;
    Node * temp=head;
    head=head->next;
    delete temp;
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
    free(temp->next);
    temp->next=nullptr;
    return head;
}
Node * deleteatIndex(Node * head,int k){
    if(head==nullptr) return nullptr;
    if(k==1){
        Node * temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int count=0;
    Node * prev=nullptr;
    Node * temp=head;
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
Node * deleteElement(Node * head,int val){
    if(head==nullptr) return nullptr;
    if(head->data==val){
        Node * temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node * prev=nullptr;
    Node * temp=head;
    while(temp!=nullptr){
        if(temp->data==val){
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
    vector<int> arr={1,2,3,4,72,5,6,7,8,9,10};
    Node * head=convert_arr_ll(arr);
    displayLL(head);
    cout<<endl;
    // head=deleteHead(head);
    // displayLL(head);
    // head=deleteTail(head);
    // displayLL(head);
    // head=deleteatIndex(head,7);
    // displayLL(head);
    head=deleteElement(head,72);
    displayLL(head);
    return 0;
}