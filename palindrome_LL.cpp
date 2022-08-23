#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }

};

void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}
Node* getmid(Node* head){

    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL){
        
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}
Node* reverse(Node* head){

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        
        next = curr ->next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
bool ispalindrome(Node* head){

    if(head == NULL || head -> next == NULL){
        return true;
    }

    Node* mid = getmid(head);

    Node* temp = mid -> next;
    mid -> next = reverse(temp);

    Node* head1 = head;

    Node* head2 = mid->next;

    while(head2 != NULL){

        if(head1 ->data != head2 -> data){
            return false;
        }
        else{
            head1 = head1 -> next;
            head2 = head2 -> next;
        }

        return true;
    }
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


int main() {
    
    //created a new node
    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
   // cout << node1 -> next << endl;
    
    //head pointed to node1
    Node* head = node1; 
    Node* tail = node1;
    print(head);

    insertAtTail(tail, 12);
    insertAtTail(tail, 15);

    print(head);

    if(ispalindrome(head) == true){
        
        cout << "This is a palindrome linked list"; 
    }
    else{
        cout << " This is not a plaindrome linked list"; 
    }

    return 0;
}