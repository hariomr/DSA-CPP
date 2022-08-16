#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

     //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

};
void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void reverselinkedlist(Node* &head){
    
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}
void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int main(){

    Node* node1 = new Node(10);
    Node* head = node1;

    insertAtHead(head , 20);
    insertAtHead(head , 14);
    insertAtHead(head , 34);
    insertAtHead(head , 65);

    reverselinkedlist(head);

    print(head);
    return 0;
}