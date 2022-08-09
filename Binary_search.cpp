#include<iostream>
using namespace std;
int binarysearch(int arr[], int n ,int key){
    int s=0 , e=n-1;

    while(s<=e){
        int m=(s+e)/2;
        if(arr[m]==key){
            return m;
        }
        else if(arr[m]<key){
            s=m+1;
        }
        else{
            e=m-1;
        }

    }
    return -1;
}
int main(){
    int n ,key;
    cout<<"Enter the size for the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter the Key: ";
    cin>>key;

    cout<<binarysearch(arr,n,key);
    return 0;
}