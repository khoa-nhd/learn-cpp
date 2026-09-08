#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<ll> s;
ll n, x;

void readData(){
    cin >> n >> x;
    for(int i = 0; i < n; ++i){
        ll temp;
        cin >> temp;
        s.insert(temp);
    }
}

ll sol(){
    ll i = 1;
    for(ll v : s){
        if(v >= x){
            return i;
        }
        i += 1;
    }
    return i;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
