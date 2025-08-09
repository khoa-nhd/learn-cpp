#include <iostream>
#include <cstdio>
using namespace std;

long long reversee(long long n){
    long long result = 0;
    while(n>0){
        result = result*10+n%10;
        n = n/10;
    }
    return result;
}

void seq22(int n){
    if(n == 0){
        cout<<8;
    } else if(n == 1){
        cout<<10;
    } else{
        int result = 1;
        for(int i = 1; i<n; ++i){
            result =  reversee(result)+2;
        }
        cout<<result;
    }
}

int main(){
    freopen("SEQ2.INP", "r", stdin);
    freopen("SEQ2.OUT", "w", stdout);
    long long n;
    while (cin >> n) {
        n = n%81;
        seq22(n);
    }
    return 0;
}


