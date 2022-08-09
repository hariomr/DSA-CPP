#include<iostream>
using namespace std;

bool binarysearch(int arr[], int start ,int end , int key){
    if(start > end){
        return false;
    }

    int mid = (start+end)/2;

    if(arr[mid] == key){
        return true;
    }
    else if(arr[mid] > key){
        return binarysearch(arr , start, mid-1 ,key);
    }
    else{
        return binarysearch(arr , mid+1 , end ,key);
    }
}

int main(){
    int arr[5] = {23,45,51,64,89};
    int start = 0;
    int end = 4;
    int key = 6;

    int ans = binarysearch(arr , start , end , key);
    if(ans == true){
        cout << "key found";
    }
    else{
        cout << "key not found";
    }
    return 0;
}