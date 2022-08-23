#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    // initialization of vector
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // traversal of vecotr using for loop
    for(int i=0 ; i<v.size() ; i++){
        cout << v[i] <<endl;
    }

    // traversal of vector using an iterator
    vector<int>::iterator it;
    
    for(it=v.begin() ; it!=v.end() ; it++){
        cout<<*it<<endl;
    }

    // traversal of vector using auto function
    for(auto element:v){
        cout<<element <<endl;
    }

    // removing the last element from the vector
    v.pop_back();

    // initalizing another vector with the v2
    vector<int> v2(3,50);

    // swapping both the vectors v and v2
    swap(v,v2);

    // printing the elements of both the vectors
    for(auto element:v){
        cout << element << endl;
    }

    for(auto element:v2){
        cout << element << endl;
    }

    sort(v.begin(),v.end());

    return 0;
}