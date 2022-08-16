#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    // constructor
    Node(int val){
        this -> data = val;
        this -> next = NULL;
    }

};

void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

int getlength(Node* &head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}
Node* Middle(Node* &head){
    
    int len = getlength(head);
    int ans = (len/2); 

    Node* temp = head;
    int cnt = 0 ;

    while(cnt < ans){
        temp = temp -> next ;
        cnt++;
    }
    cout << temp ->data << endl;
    return temp;
}
int main(){

    Node* node1 = new Node(10);
    Node* head = node1;

    insertAtHead(head , 20);
    insertAtHead(head , 14);
    insertAtHead(head , 34);
    insertAtHead(head , 65);

    Middle (head);

    return 0;
}