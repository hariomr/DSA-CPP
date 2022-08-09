#include<iostream>
using namespace std;

class Node {
    
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    // destructor
    ~Node(){
        int value = this -> data;
        //memory free
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data <<" ";
        temp = temp -> next;
    }
    cout << endl;
}
 int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        len ++;
        temp = temp -> next;
    }
    return len;
}
void insertAtHead(Node* &tail ,Node* &head , int d){
//    empty
   if(head == NULL){
       Node* temp = new Node(d);
       head = temp;
       tail = temp;
   }
   else{
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
   }
}
void insertAtTail(Node* &tail, Node* &head, int d){
    if(tail == NULL){
       Node* temp = new Node(d);
       head = temp;
       tail = temp;
    }
    else{
        Node* temp = new Node(d);
        tail ->next = temp;
        temp ->prev = tail;
        tail = temp; 
    }
}
void insertAtPosition(Node* &tail ,Node* &head , int position ,int d){

     if(position == 1){
        insertAtHead(tail,head, d);
        return;
    }

    Node* temp = head;
          
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

     // inserting at last position
    if(temp ->next == NULL){
        insertAtTail(tail, head ,d);
        return;
    }

    // inserting at middle

        Node* nodeToinsert = new Node(d);
        nodeToinsert ->next = temp->next;
        temp ->next ->prev = nodeToinsert;
        temp ->next = nodeToinsert;
        nodeToinsert ->prev = temp;
        
}

void deleteNode(int position , Node* &head){

    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next; 
        temp -> next = NULL;

        delete temp;
    }
    else{
        // deleting any last node or middle node 
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next; 
            cnt++;
        }
        curr -> prev = NULL;
        prev ->next = curr->next;
        curr -> next = NULL;

        delete curr;

    }
}

int main(){
    
    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    cout << getLength(head)<<endl;

    insertAtHead(tail,head, 11);
    print(head);

    insertAtHead(tail,head, 22);
    print(head);

    insertAtHead(tail,head, 25);
    print(head);

    insertAtTail(tail, head, 16);
    print(head);

    insertAtPosition(tail , head, 2 ,55);
    print(head);

    insertAtPosition(tail , head, 1 , 101);
    print(head);

    insertAtPosition(tail , head, 4 ,58);
    print(head);

    insertAtPosition(tail , head, 8 ,55);
    print(head);

    deleteNode(1,head);
    print(head);

    deleteNode(3,head);
    print(head);

    return 0;
}