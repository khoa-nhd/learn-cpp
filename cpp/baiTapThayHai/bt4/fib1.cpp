#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fib[50] = {};

void genFib(){
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i <= 45; ++i){
        fib[i] = fib[i-2] + fib[i-1];
    }
//    for(int i = 0; i <= 45; ++i){
//        cout << fib[i] << "\n";
//    }
}

char fib1(ll n, ll k){
    if(n == 0) return 'a';
    if(n == 1) return 'b';
    if(k <= fib[n-2]){
        return fib1(n-2, k);
    } else{
        return fib1(n-1, k-fib[n-2]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FIB1.INP", "r", stdin);
    freopen("FIB1.OUT", "w", stdout);
    genFib();
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll n, k;
        cin >> n >> k;
        char result;
        result = fib1(n, k);
        cout << result << "\n";
    }
    return 0;
}
