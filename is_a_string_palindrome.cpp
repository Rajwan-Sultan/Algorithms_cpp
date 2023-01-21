#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string s){
    int n=s.size();
    int l=0,r=n-1;
    while(l<r){
        if(s[l]!=s[r])
        return false;
    l++;
    r--;
    }
return true;
}

/* 
level
eve
 */
bool is_palindrome_rec(string s){
    if(s==""||s.size()==1)
    return true;
    int n=s.size();
    string small_string=s.substr(1,n-2);
    return is_palindrome_rec(small_string) && (s[0]==s.back());
}

int main(){

    string s;
    cin >> s;
    if(is_palindrome_rec(s)){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not Palindrome"<<endl;
    }
    return 0;
}