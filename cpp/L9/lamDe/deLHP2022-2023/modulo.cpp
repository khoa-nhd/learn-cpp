#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[1000005];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void modulo(){
    set<ll> res;
    for(int i = 1; i < n; ++i){
        a[i] = abs(a[i] - a[0]);
    }
    ll g = 0;
    for(int i = 1; i < n; ++i){
        g = __gcd(a[i] , g);
    }
    ll loop = sqrt(g);
    res.insert(g);
    for(int i = 2; i <= loop; ++i){
        if(g % i == 0){
            res.insert(i);
            res.insert(g/i);
        }
    }
    for(ll x : res) cout << x << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    modulo();
    return 0;
}

