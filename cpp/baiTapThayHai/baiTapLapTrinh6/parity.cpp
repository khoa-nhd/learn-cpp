#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN] = {};
ll prefix[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        ll temp;
        cin >> temp;
        if(temp % 2 == 0) a[i] = 1;
        else a[i] = -1;
    }
}

ll parity(){
    for(int i = 1; i <= n; ++i){
        prefix[i] = prefix[i-1] + a[i-1];
    }
    unordered_map<ll, ll> m;
    ll res = 0;
    for(int i = 0; i <= n; ++i){
        res += m[prefix[i]];
        m[prefix[i]] += 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PARITY.INP", "r", stdin);
    freopen("PARITY.OUT", "w", stdout);
    readData();
    ll res;
    res = parity();
    cout << res;
    return 0;
}
