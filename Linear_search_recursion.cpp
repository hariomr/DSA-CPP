#include<iostream>
using namespace std;

int linearsearch(int arr[], int size , int key){
    if(size == 0){
        return 0;
    }
    if(arr[0]==key){
        return 1;
    }
    else{
        int remainingpart = linearsearch(arr+1,  size-1, key);
        return remainingpart;
    }

}

int main(){
    int arr[5]={2,3,4,5,7};
    int size = 5 ; 
    int key = 2;

    int ans  = linearsearch(arr, size , key);

    if(ans){
        cout<<"Key found";
    }
    else{
        cout<<"Key not found";
    }

    return 0;
}