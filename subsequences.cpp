#include<iostream>
using namespace std;
int subsequences(string str , string output[]){
    if(str.length()==0){
        output[0]="";
        return 1;
    }
    int smalleroutputsize=subsequences(str.substr(1),output);
    for(int i=0 ; i<smalleroutputsize ; i++){
        output[i+smalleroutputsize]=str[0]+output[i];
    }

    return 2*smalleroutputsize;

}
int main(){

    string output[1000];

    int outputsize = subsequences("abc",output);

    for(int i=0 ; i<outputsize ; i++){
        cout<<output[i]<<endl;
    }
    return 0;
}