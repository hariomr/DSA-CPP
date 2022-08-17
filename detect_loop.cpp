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
bool detectloop(Node* &head){
    
    if(head == NULL){
        return false;
    }

    map<Node*, bool> visited;

    Node* temp = head;
    while (temp != NULL)
    {
        if(visited[temp] == true){
            return true;
        }

        visited[temp] = true;
        temp = temp ->next;
    }
    return false;
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

    tail -> next = head ->next;
    cout << "Tail is " << tail ->data << endl;
    cout << "Head is " << head ->data << endl;

    // print(head);

    if(detectloop(head)){
        cout << "Cycle is present"<<endl;
    }
    else{
        cout << "Cycle is not present"<<endl; 
    }

    return 0;
}