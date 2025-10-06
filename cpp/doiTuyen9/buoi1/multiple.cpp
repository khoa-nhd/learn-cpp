#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll multiple(ll n, ll q){
    ll result = 0;
    ll mu = 1;
    for(int i = 0; i < n; ++i){
        result = result % 2023 + mu;
        mu *= q;
        mu %= 2023;
    }
    result %= 2023;
    return result;
}

int main(){
    ll n, q;
    cin >> n >> q;
    ll m;
    m = multiple(n, q);
    cout << m;
    return 0;
}
