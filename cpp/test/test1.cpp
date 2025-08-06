#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int code(int t){
    int length = 0, longest = 0;
    string a;
    for(int i = 1; i<=t; ++i){
        cin>>a;
        if (a == "ONLINE"){
            length += 1;
        } else{
            length = 0;
        }
        if(length > longest){
            longest = length;
        }
    }
    return longest;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("result.txt", "w", stdout);
    int result, t;
    cin>>t;
    result = code(t);
    cout<<result;
    return 0;
}

