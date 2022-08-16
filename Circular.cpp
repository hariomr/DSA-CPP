#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    // constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    // destructor
    ~Node(){
        int value = this ->data;
        if(next != NULL){
            delete next;
            next = NULL; 
        }
        cout << "Memory is free for node with data " << value << endl;
    }

};

void insertAtNode(Node* &tail, int element , int d){
    // assuming that the element is present in the list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        // non-empty list
        Node* curr = tail;
        
        while(curr->data != element){
            curr = curr -> next;
        }
        
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;


    }
}
bool iscircular(Node* &tail){
    // empty list
    if(tail == NULL){
        return true;
    }

    Node* temp = tail->next;

    while(temp != NULL && temp != tail){
        temp = temp ->next;
    }

    if(temp == tail){
        return true;
    }

    return false;
}
void print (Node* tail){
    Node* temp = tail;

    if(tail == NULL){
        cout << "List is empty" << endl;
        return;
    }
    do{
        cout << tail ->data <<" ";
        tail = tail -> next;
    }while(tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int value){
    // empty list
    if(tail == NULL){
        cout << "List is empty, please check again" << endl;
    }
    else{
        // non-empty

        Node* prev = tail;
        Node* curr = prev ->next;

        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;

        // one Node linked list 
        if(curr == prev){
            tail = NULL;
        }
        if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}
int main(){
    Node* tail = NULL;

    insertAtNode(tail,3,5);
    print(tail); 

    insertAtNode(tail,5,7);
    print(tail); 

    insertAtNode(tail,7,9);
    print(tail); 

    // deleteNode(tail ,5);
    // print(tail);

    if(iscircular(tail)){
        cout << "Linked list is circular in nature" << endl; 
    }
    else{
        cout << "Linked list is not circular";
    }


    return 0;
}