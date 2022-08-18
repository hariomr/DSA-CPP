#include<iostream>
#include<map>
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
Node* Floydcycle(Node* head){
    
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        
        if(fast != NULL){
            fast = fast ->next;
        }

        slow = slow ->next; 

        if(slow == fast){
            return slow;
        }
    
    }
    return NULL;
}

Node* getstartingNode(Node* head){
    
    if(head == NULL){
        return NULL;
    }
    
    Node* intersection = Floydcycle(head);
    Node* slow = head;

    while(slow != intersection){
        
        slow = slow -> next;
        intersection = intersection ->next ;
    }

    return slow;
}

void removeloop(Node* head){

    if(head == NULL){
        return; 
    }

    Node* startingofloop = getstartingNode(head);
    Node* temp = startingofloop;

    while(temp ->next != startingofloop){
        temp = temp ->next;
    }

    temp ->next = NULL;
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
    Node* tail = node1;

    insertAtHead(head , 20);
    insertAtHead(head , 14);
    insertAtHead(head , 34);
    insertAtHead(head , 65);
    insertAtHead(head , 89);

    // print(head);

    tail -> next = head -> next;

    if(Floydcycle(head) != NULL){
        cout << "cycle is present" << endl;
    }
    else{
        cout << "Cycle is not present" << endl;
    }

    Node* loop = getstartingNode(head);
    cout << "loop starting at " << loop ->data << endl;

    removeloop(head);
    print(head);

    return 0;
}