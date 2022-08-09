// 14.  *********
//       *     *
//        *   *
//         * *
//          *
#include<iostream>
using namespace std;

int main(){
    int n=5;
    for(int i=1 ;i<=n ;i++){
        for(int j=1; j<=2*n-1 ;j++){
            if(i==1 || j==i || i+j==2*n){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}