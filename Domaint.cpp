#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n ;
    cin >> n;

    int arr[n];
    map<int , int > mp;

    

    for(int i =0 ; i<n ; i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }

    vector<int>v;
    for(auto itr:mp){
        v.push_back(itr.second);
    }

    int max_val = -99999999;

    for(auto itr : v){
       max_val =  max(max_val , itr);
    }

    int count = 0;
    for(auto itr : v){
        if(max_val == itr){
            count ++;
        }
    }

    cout << max_val << endl;

    if(count == 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}