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
void reverselinkedlist(Node* &head , Node* curr ,Node* prev){

    // base case 
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr -> next;
    reverselinkedlist(head, forward , curr);
    curr -> next = prev; 


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

    reverselinkedlist(head , head , NULL);
    
    print(head);
    return 0;
}