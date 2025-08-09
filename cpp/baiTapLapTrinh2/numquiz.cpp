#include <iostream>
#include <cstdio>
#include <numeric>
using namespace std;
#define maxN 1000000

int a[maxN], n;

void readData(){
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
}

long long gcd(long long x, long long y){
    long long m = 0;
    if (x == 0||y == 0){
        return 0;
    }
    while(y != 0){
        m = x;
        x = y;
        y = m % y;
    }
    return x;
}

long long numquiz(){
    long long result = 0;
    for(int i = 1; i<n; ++i){
        a[i] = gcd(a[i-1], a[i]);
    }
    result = a[n-1] * n;
    return result;
}

int main(){
    freopen("NUMQUIZ.INP", "r", stdin);
    freopen("NUMQUIZ.OUT", "w", stdout);
    long long m;
    readData();
    m = numquiz();
    cout<<m;
    return 0;
}

