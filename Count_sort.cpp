#include<iostream>
using namespace std;

void countsort(int *arr, int n){
    int i, j;
    int k = arr[0];

    for(i=0 ; i<n ;i++){
        k = max(k, arr[i]);
    }

    int count[100] = {0}; 
    for(i = 0 ;i<n ; i++){
        count[arr[i]]++;
    }

     i= 0;
     j= 0; 

     while(i <= k){
        if(count[i]>0){
            arr[j] = i;
            count[i] = count[i] -1;
            j++;
        }
        else{
            i++;
        }

     }
}

int main(){
    
    int arr[5] = {23, 2, 1,56 ,1};
    int n =5;

    countsort(arr, n);

    for(int i=0 ;i<n ;i++){
        cout << arr[i] <<" ";
    }

    return 0;
}