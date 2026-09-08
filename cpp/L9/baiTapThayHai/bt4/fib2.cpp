#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fib[50] = {};
ll fibo[50] = {};

void genFib(){
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i <= 45; ++i){
        fib[i] = fib[i-2] + fib[i-1];
    }
    fibo[0] = 1;
    fibo[1] = 0;
    for(int i = 2; i <= 45; ++i){
        fibo[i] = fibo[i-2] + fibo[i-1];
    }
//    for(int i = 0; i <= 45; ++i){
//        cout << fib[i] << "\n";
//    }
//    for(int i = 0; i <= 45; ++i){
//        cout << fibo[i] << "\n";
//    }
}

ll fib2(ll n, ll k){
    if(n == 0) return 1;
    if(n == 1) return 0;
    if(k <= fib[n-2]){
        return fib2(n-2, k);
    } else{
        return fibo[n-2] + fib2(n-1, k-fib[n-2]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FIB2.INP", "r", stdin);
    freopen("FIB2.OUT", "w", stdout);
    genFib();
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll n, k;
        cin >> n >> k;
        ll result;
        result = fib2(n, k);
        cout << result << "\n";
    }
    return 0;
}
