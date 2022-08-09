#include<iostream>
using namespace std;
int main(){
    int n ,key;
    cout<<"Enter the size of an array: ";
    cin>>n;
    
    int arr[n];

    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n ;i++){
        cin>>arr[i];
    }

    cout<<"Enter the Key:";
    cin>>key;
    int flag=0;
    for(int i=0; i<n ;i++){
        if(key==arr[i]){
            cout<<"Key found at "<<i<<" index";
            flag=1;
        }
    }
    if(flag==0){
        cout<<"Key not found";
    }

    return 0;
}