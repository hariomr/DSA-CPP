#include<iostream>
using namespace std;
bool checkpalindrome(string& str , int i , int j){
    if(i > j){
        return true;
    }

    if(str[i] != str[j]){
        return false;
    }
    else{
        return checkpalindrome(str , i+1, j-1);
    }
}
int main(){

    string str = "wow";
    int check =  checkpalindrome(str , 0 ,str.length()-1);
    if(check == true){
        cout<<"It's a Palindrome String";
    } 
    else{
        cout<<"It's not da Palindrome string";
    }
    return 0;
}