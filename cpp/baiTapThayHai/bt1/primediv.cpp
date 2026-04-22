// Ghi ra các ước số nguyên tố của n theo thứ tự tăng dần và cách không lặp lại số
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
void primediv(long long n){
    int i = 3;
    long long result = 0;
    bool chiahetcho2 = false;
    while(n%2==0){
        n = n / 2;
        chiahetcho2 = true;
    }
    if (chiahetcho2){
        cout<<2<<" ";
    }
    while ((long long)i*i<=n){
        if (n % i == 0){
            n = n / i;
            cout<<i<<" ";
            while (n % i == 0) n /= i;
        } else{
            i = i + 2;
        }
    }
    if(n>1){
        cout<<n;
    }
}
int main(){
    freopen("PRIMEDIV.INP", "r", stdin);
    freopen("PRIMEDIV.OUT", "w", stdout);
    long long n;
    cin >> n;
    primediv(n);
    return 0;
}
