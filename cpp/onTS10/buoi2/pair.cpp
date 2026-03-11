#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, g;

void sol(){
    ll a = l, b = g;
    ll res = l + g;
    ll product = a * b;
    for(ll i = l+1; i < g; ++i){
        if(product % i != 0) continue;
        ll j = product / i;
        if(__gcd(i, j) == l && product / __gcd(i, j) == g){
            if(res > i + j){
                res = i + j;
                a = i;
                b = j;
            }
        }
    }
    cout << min(a, b) << " " << max(a, b);
}

int main(){
    cin >> l >> g;
    sol();
    return 0;
}
