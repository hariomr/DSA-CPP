// Highest common factor
// Euclid principle
#include<iostream>
using namespace std;

int gcd(int a , int b){
    while(b!=0){
        int c= a % b;
        a = b; 
        b = c;
    }
    return a;
}
int lcm (int a ,int b){
    int c=(a*b)/gcd(a,b);
    return c;
}
int main(){
    
    int a ,b;

    cout<<"Enter any two Numbers : ";

    cin >> a>>b; 

    cout<<"GCD of entered number is :"<<gcd(a,b)<<endl;

    cout<<"LCM of the entered numbers are: "<<lcm(a,b);

    return 0;
}