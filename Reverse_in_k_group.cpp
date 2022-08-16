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

Node* Kreverse(Node* head, int k){
    if(head == NULL){
        return NULL;
    }
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0; 

    while (curr != NULL && count < k)
    {
        next = curr -> next;
        curr -> next = prev; 
        prev = curr;
        curr  = next;
        count++ ;
    }
    if(next != NULL){
        head -> next = Kreverse(next ,k);
    }

    return prev;
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

    
    Node* newhead = Kreverse(head , 3);
    print(newhead);

    return 0;
}
