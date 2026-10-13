#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n;
ll a[maxN];
ll dem[2000] = {};

ll tobit(ll x){
    ll res = 0;
    while(x > 0){
        ll c = x % 10;
        res = res | (1 << c);
        x /= 10;
    }
    return res;
}

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        a[i] = tobit(a[i]);
    }
}

void sol(){
    ll res = 0;
    for(int i = 0; i < n; ++i) dem[a[i]] += 1;
    for(int i = 0; i <= 1024; ++i){
        for(int j = i+1; j <= 1024; ++j){
            if((i & j) > 0){
                res += dem[i] * dem[j];
//                if(dem[i] * dem[j] > 0) cout << i << " " << j << "\n";
            }
        }
    }
    for(int i = 0; i <= 1024; ++i){
        res += max(0LL, (dem[i] * (dem[i] - 1)) / 2);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CLOSEPAIRS.INP", "r", stdin);
    freopen("CLOSEPAIRS.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
