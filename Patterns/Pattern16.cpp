// 16.           1        
//             1   1
//           1   2   1
//         1   3   3   1
//       1   4   6   4   1

#include<iostream>
using namespace std;
int main(){
    int n=5;
    for(int i=1; i<n; i++){
        for(int j=1 ;j<=2*n-1-i;j++){
            cout<<" ";
        }
        for(int j=1 ;j<=2*n+1-i;j++){
            cout<<" ";
        }

    }
    return 0;
}