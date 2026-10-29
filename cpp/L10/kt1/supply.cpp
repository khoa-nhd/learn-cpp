#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
ll bcnn[105] = {};

void test(){
    ll lcm = 1;
    for(ll i = 1; i <= 42; ++i){
//        if(lcm > 1e18 / i) cout << "HEREEEEEEEEEEEEEEEE\n";
        lcm = (lcm * i) / __gcd(i, lcm);
        bcnn[i] = lcm;
//        cout << lcm << "\n";
    }
}

void sol(){
    if(k > 42){
        cout << 1;
        return;
    }
    if(((n-1) / bcnn[k]) == 0){
        cout << 1;
        return;
    }
    ll res = ((n-1) / bcnn[k]) * bcnn[k] + 1;
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUPPLY.INP", "r", stdin);
    freopen("SUPPLY.OUT", "w", stdout);
    cin >> n >> k;
    test();
    sol();
    return 0;
}
