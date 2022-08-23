#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    // contructors

    Node(int val){
        this ->data = val;
        this ->next = NULL;
    } 
};

Node* insertAtTail(Node* &tail , int d){

    Node* temp = new Node(d);
    tail ->next = temp;
    tail = temp;
}

Node* sortlist(Node* head){

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* TwoHead = new Node(-1);
    Node* TwoTail = TwoHead;

    Node* curr = head;

    while(curr != NULL){

        int value = curr ->data;

        if(value == 0){
            insertAtTail(zeroTail, curr);
        }

        else if (value == 1){
            insertAtTail(oneTail , value);
        }

        else if(value == 2){
            insertAtTail(TwoTail , value);
        }

        curr = curr -> next;
    }

    // Merging 3LL
    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
    }
    else{
        zeroTail -> next = TwoHead -> next;
    }

    oneTail -> next = TwoHead -> next;
    TwoTail ->next = NULL;
    
    head = zeroHead -> next;

    delete zeroHead;
    delete oneHead;
    delete TwoHead;
}

void print(Node* &head){

    if(head == NULL){
        return;
    }

    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp ->next;  
    }
}

int main(){

    Node* node1 = new Node(2);
    Node* head = node1;
    Node* tail = node1;
    
    insertAtTail(tail , 2);
    insertAtTail(tail , 0);
    insertAtTail(tail , 2);
    insertAtTail(tail , 0);
    insertAtTail(tail , 1);

    print(head);

    Node* sort = sortlist(tail);
    print(sort);

    return 0;
}