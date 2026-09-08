#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll digit[100000] = {};

ll sochuso(ll x){
    ll res = 0;
    while(x > 0){
        res += x % 10;
        x /= 10;
    }
    return res;
}

void prep(){
    for(int i = 1000; i <= 9999; ++i){
        digit[i] = sochuso(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    prep();
    for(int i = 0; i < t; ++i){
        cin >> n;
        ll res = 0;
        for(int i = 1000; i <= 9999; ++i){
            if(digit[i] == n){
                res += 1;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
