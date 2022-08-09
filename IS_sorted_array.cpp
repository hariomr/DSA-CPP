#include<iostream>
using namespace std;

bool issorted(int arr[] , int size){
    
    if(size==1 || size==0){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }
    else{
        bool remainingpart = issorted(arr + 1 , size - 1);
        return remainingpart;
    }
}

int main(){
    int arr[5] = {10,4,6,8,9};
    int size = 5; 

    bool ans = issorted(arr, size);

    if(ans){
        cout << "Array is sorted" << endl; 
    }
    else{
        cout << "Array is not sorted" << endl;
    }

    return 0;
}