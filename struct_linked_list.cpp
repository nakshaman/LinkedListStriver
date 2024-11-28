#include <bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node *next;
    Node(int data_inp,Node *new_ptr){
        data=data_inp;
        next=new_ptr;
    }
};
int main (){
    Node *y=new Node(2,nullptr);
    cout<<y->data<<endl;
    cout<<y->next<<endl;
    return 0;
}