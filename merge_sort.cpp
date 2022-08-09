#include<iostream>
using namespace std;

void merge(int *arr ,int s ,int e){ 

    int mid =(s+e)/2;
// finding length
    int len1 = mid-s+1;
    int len2 = e - mid;
// Making array
    int *first = new int[len1];
    int *second = new int[len2];

// Copying Values

    int mainarrayindex = s;
    for(int i=0 ; i<len1 ;i++){
        first[i] = arr[mainarrayindex++];
    }

    mainarrayindex = mid+1;
    for(int i=0 ; i<len2 ; i++){
        second[i] = arr[mainarrayindex++];
    }

    // Merge

    int i = 0;
    int j = 0;
    mainarrayindex = s;
    while(i < len1 && j < len2){
        if(first[i] < second[j]){
            arr[mainarrayindex++] = first[i++];
        }
        else{
            arr[mainarrayindex++] = second[j++];
        }
    }

    while(i < len1){
        arr[mainarrayindex++] = first[i++];
    }
    while(j < len2){
        arr[mainarrayindex++] = second[j++];
    }
}

void mergeSort(int *arr ,int s ,int e){
    if(s >= e){
        return;
    }

    int mid = (s+e)/2;

    // left part sorting 
    mergeSort(arr, s ,mid);
    // Right part sorting
    mergeSort(arr, mid+1 ,e);

    merge(arr ,s ,e);

}

int main(){

    int arr[5] = {2,5,1,6,9};
    int n = 5;

    mergeSort(arr , 0 ,n-1);

    for(int i=0 ; i<n ; i++){
        cout << arr[i] <<endl;
    }

    return 0;
} 