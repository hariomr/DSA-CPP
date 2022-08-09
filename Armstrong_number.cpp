 
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n, sum=0;
    cout<<"Enter a three digit number: ";
    cin>>n;
    int originaln=n;                //Storing the value of original n to check it later.
    while(n>0){
        int lastdigt=n%10;                 // for getting th last digit of a number.
        sum+=lastdigt*lastdigt*lastdigt;       
        n=n/10;                     // for getting the remainder means the number after removing it lasdigit.
    }
    if(sum==originaln){
        cout<<"Number is Armstrong";
    }
    else{
        cout<<"Number is not an Armstrong";
    }
    return 0;
}