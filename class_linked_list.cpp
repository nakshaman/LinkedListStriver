#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int input_data,Node *new_ptr){
        data=input_data;
        next=new_ptr;
    }
};
int main (){
    Node *a=new Node(7,nullptr);
    cout<<a->data<<endl;
    cout<<a->next<<endl;
    return 0;
}