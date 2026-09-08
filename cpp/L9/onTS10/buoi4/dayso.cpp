#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, x, a[maxN];
map<ll, ll> cnt;

void readData(){
    cin >> n >> x;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll sol(){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        cnt[a[i]] += 1;
        ll need = x - a[i] * a[i];
        if(need > 0){
            res += cnt[need];
        }
    }
    return res;
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
