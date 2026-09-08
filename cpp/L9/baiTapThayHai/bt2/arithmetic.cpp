#include <iostream>
#include <cstdio>
#include <numeric>
using namespace std;
#define maxN 1000000

long long a[maxN], b[maxN], n;

void readData(){
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
}

void cong(int n){
    int soChia = 1000000007;
    for(int i = 0; i<n; ++i){
        b[i] = (a[i]+a[i+1])%soChia;
    }
}

void nhan(int n){
    int soChia = 1000000007;
    for(int i = 0; i<n; ++i){
        a[i] = (b[i]*b[i+1])%soChia;
    }
}

long long arithmetic(){
    long long result = 0;
    int n1 = n-1, i = 0;
    n -= 1;
    for(i = 0; i<n1; ++i){
        if(i%2 == 0){
            cong(n);
            n -= 1;
        } else{
            nhan(n);
            n -= 1;
        }
    }
    if((n1+1)%2 == 0){
        result = b[0];
    } else{
        result = a[0];
    }
    return result;
}

int main(){
    freopen("ARITHMETIC.INP", "r", stdin);
    freopen("ARITHMETIC.OUT", "w", stdout);
    long long m;
    readData();
    m = arithmetic();
    cout<<m;
    return 0;
}

