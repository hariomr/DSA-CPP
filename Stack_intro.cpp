#include<iostream>
#include<stack>
using namespace std;

int main(){

    // creation of stack
    stack <int> s;

    // pushing elements in stack 
    s.push(22);
    s.push(43);
    s.push(44);
    s.push(48);

    // removing elements from the stack
    s.pop();
    s.pop();

    // peaking the stack
    cout << "The top element of stack is " << s.top() <<endl;

    if(s.empty()){
        cout << "Stack is empty" << endl;
    }
    cout<< "Stack is not empty" << endl;
    return 0;
}