#include<iostream>
using namespace std;
void bubblesort(int arr[] , int n){
    if(n == 0){
        return ;
    }
    for(int i=0 ; i<n ; i++){
        if(arr[i] > arr [i+1]){
            swap (arr[i] ,arr[i+1]);
        }                                                                                                                      
    }
   return bubblesort(arr, n-1);
}
int main(){

    int arr[5] = {65,6,85,12,22};
    int n = 5;

    bubblesort(arr,n);

    for(int i=0 ; i<5 ; i++){
        cout<< arr[i] << " ";
    }
    return 0;
}