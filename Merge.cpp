#include<iostream>
using namespace std;

void merge(int *arr , int s , int e){

    int mid = (s+e)/2;

    int len1 = mid-s+1 ;
    int len2 = e-mid;

    int *first = new int[len1];
    int *Second = new int[len2];


    int mainindexArray = s;

    for(int i=0 ; i<len1 ; i++){
        first[i] = arr[mainindexArray++]; 
    }

    mainindexArray = mid+1;

    for(int i=0 ; i<len2 ; i++){
        Second[i] = arr[mainindexArray++]; 
    }

    int index1 = 0;
    int index2 = 0; 
    mainindexArray = s;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < Second[index2]){
            arr[mainindexArray++] = first[index1++];
        }
        else{
            arr[mainindexArray++] = Second[index2++];
        }
    }

    while(index1 < len1){
        arr[mainindexArray++] = first[index1++];
    }
    while(index2 < len2){
        arr[mainindexArray++] = Second[index2++];
    }
}
void mergesort(int *arr , int s , int e){

    if(s >= e){
        return;
    }
    
    int mid = (s+e)/2;

    mergesort(arr , s ,mid);
    mergesort(arr , mid+1 ,e);

    merge( arr , s , e);

}
int main(){
    int arr[5] = {2,43,2,34,4};

    int n = 5;

    mergesort(arr , 0 , n-1);

    for(int i = 0 ; i<n ;i++){
        cout << arr[i] << " "; 
    }
    return 0;
}