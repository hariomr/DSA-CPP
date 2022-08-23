#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    // constructor 
    Node(int val){
        this->data = val;
        this ->next = NULL;
    }

    // destructor

    ~Node(){
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
    }
};
void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
Node* sortlist(Node* head){
    
    int zerocount = 0 ;    
    int onecount = 0 ;    
    int Twocount = 0 ;    

    Node* temp = head;

    while(temp != NULL){

        if(temp -> data == 0){
            zerocount ++ ;
        }
        else if(temp -> data == 1){
            onecount ++ ;
        }
        else if(temp -> data == 2){
            Twocount ++;
        }

        temp = temp ->next;
    }

    temp = head;
    while(temp != NULL){

        if(zerocount != 0){
            temp -> data = 0;
            zerocount --;
        }

        else if(onecount != 0){
            temp -> data = 1;
            onecount --;
        }

        else if(Twocount != 0){
            temp -> data = 2;
            Twocount --;
        }
        temp = temp ->next;
    }
    return head;
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
    
    Node* node1 = new Node(2);
    Node* head = node1;

    insertAtHead(head , 2);  
    insertAtHead(head , 1);  
    insertAtHead(head , 2);
    insertAtHead(head , 0);

    print(head);

    Node* sortedLL = sortlist(head);
    print(sortedLL);

    return 0;
}
