#include<iostream>
using namespace std;
class Node{

    public:
    int data;
    Node* next;

    // constructor
    Node(int val){
        this ->data = val;
        this -> next = NULL;
    }
};
void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
bool iscircular(Node* &head){
    // empty list
    if(head == NULL){
        return true;
    }

    Node* temp = head->next;

    while(temp != NULL && temp != head){
        temp = temp ->next;
    }

    if(temp == head){
        return true;
    }

    return false;
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
    insertAtHead(head , 89);

    print(head);

    if(iscircular(head)){
        cout << "Linked list is circular in nature" << endl; 
    }
    else{
        cout << "Linked list is not circular";
    }

    return 0;
}