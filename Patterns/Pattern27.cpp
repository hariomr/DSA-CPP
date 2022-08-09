// 27.   1 2 3 4  17 18 19 20
//         5 6 7  14 15 16
//           8 9  12 13
//             10 11
#include<iostream>
using namespace std;
int main(){
    int n=4 , count=1 , c=11;
    for(int i=0; i<n ; i++){
        for(int j=1 ; j<=i; j++){
            cout<<" ";
        }
        for(int j=1 ;j<=n-i ;j++){
            cout<<count;
            count++;
        }
        for(int j=1 ; j<=2 ;j++){
            cout<<" ";
        }
        for(int j=1 ;j<=n-i ;j++){
            cout<<c;
            c++;
        }
        cout<<endl;
    }
    return 0;
}