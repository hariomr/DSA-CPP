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
bool checkpalindrome(vector<int> arr){

    int n = arr.size();
    int s = 0;
    int e = n-1;

    while(s <= e){

        if(arr[s] != arr[e]){
            return 0;
        }
        s++;
        e--;    
    }
}
bool ispalindrome(Node* head){

    vector<int> arr;

    Node* temp = head ;
    while(temp != NULL){
        
        arr.push_back(temp -> data);
        temp = temp -> next;
    }
    return checkpalindrome(arr);
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
    insertAtTail(tail, 10);

    print(head);

    if(ispalindrome(head) == true){
        
        cout << "This is a palindrome linked list"; 
    }
    else{
        cout << " This is not a plaindrome linked list"; 
    }

    return 0;
}