#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll> t;
vector<ll> p;
ll cnt = 0;

void weights(){
    ll somu = 0;
    while(n > 0){
        ll r = n % 3;
        n /= 3;
        if(r == 1){
            t.push_back(somu);
        } else if(r == 2){
            p.push_back(somu);
            n += 1;
        }
        somu += 1;
    }
    for(ll x : t) cout << x << " ";
    cout << "\n";
    for(ll x : p) cout << x << " ";
}

int main(){
    freopen("WEIGHTS.INP", "r", stdin);
    freopen("WEIGHTS.OUT", "w", stdout);
    cin >> n;
    weights();
    return 0;
}
