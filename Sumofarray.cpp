#include<iostream>
using namespace std;

int sumofarray(int arr[], int size){
    
    if(size == 0){
        return 0;
    }
    
    int remainingpart = sumofarray(arr+1 , size-1);
    int sum = arr[0] + remainingpart;
    return sum;
}

int main(){

    int arr[1] = {3};
    int size = 1; 
    int sum = sumofarray(arr , size);

    cout<<"Sum is "<<sum;
    return 0;
}