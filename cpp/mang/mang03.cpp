// Cho n
// Hãy xem từ a1 đến an có bao nhiêu số nguyên tố
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define maxN 1000000

int a[maxN], n;

void readData(){
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
}

bool primeNumber(int n){
    if (n <= 1){
        return false;
    }
    int m = sqrt(n);
    for(int i = 2; i<=m; ++i){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int mang03(){
    int s = 0;
    for(int i = 0; i < n; ++i){
        if(primeNumber(a[i])){
            s = s + 1;
        }
    }
    return s;
}

int main(){
    freopen("MANG03.INP", "r", stdin);
    freopen("MANG03.OUT", "w", stdout);
    int m;
    readData();
    m = mang03();
    cout<<m;
    return 0;
}

