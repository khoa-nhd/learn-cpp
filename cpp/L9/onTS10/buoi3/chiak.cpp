#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

unordered_map<ll, ll> m;
ll n, k, a[maxN];

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void sol(){
    m[0] = 1;
    ll sum = 0;
    ll res = 0;
    for(int i = 0; i < n; ++i){
        sum += a[i];
        ll mod = (sum % k + k) % k;
        res += m[mod];
        m[mod] += 1;
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
