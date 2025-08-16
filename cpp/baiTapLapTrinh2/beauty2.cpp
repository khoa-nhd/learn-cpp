#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int a[10000];

long long tongBinhPhuong(int n){
    long long result = 0;
    while(n>0){
        result = result + (n%10)*(n%10);
        n = n/10;
    }
    return result;
}

bool checkPrime(int n){
    if(n == 1 || n == 0){
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

void beauty2(){
    int i = 0, j = 0;
    while (j<10000){
        if(checkPrime(tongBinhPhuong(i))){
            a[j] = i;
            j += 1;
        }
        i += 1;
    }
}

int main(){
    freopen("BEAUTY2.INP", "r", stdin);
    freopen("BEAUTY2.OUT", "w", stdout);
    int m;
    beauty2();
    while(cin >> m){
        cout << a[m-1];
    }
    return 0;
}
