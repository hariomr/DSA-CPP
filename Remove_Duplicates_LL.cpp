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
Node* removeduplicates(Node*head){
        
        if(head == NULL){
            return NULL;
        }

        Node* curr = head;

        while(curr != NULL){
            
            if((curr ->next != NULL) && curr -> data == curr ->next ->data){
                Node* next_next = curr -> next ->next ;
                Node* nodeToDelete = curr -> next; 
                cout << nodeToDelete -> data << endl;
                delete(nodeToDelete);

                cout << next_next -> data << endl;
                curr -> next = next_next;
            }
            else{
                curr = curr -> next;
            }
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
    
    Node* node1 = new Node(10);
    Node* head = node1;

    insertAtHead(head , 59);  
    insertAtHead(head , 59);  
    insertAtHead(head , 49);
    insertAtHead(head , 49);

    print(head);

    Node* rmduplicates = removeduplicates(head);
    print(rmduplicates);

    return 0;
}
