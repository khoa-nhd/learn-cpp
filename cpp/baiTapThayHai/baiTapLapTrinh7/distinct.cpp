#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, k, a[maxN];
ll d[maxN] = {};

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void sang(){
    for(int i = 2; i * i < maxN; ++i){
        if(d[i] == 0){
            for(int j = i * i; j < maxN; j += i){
                d[j] = i;
            }
        }
    }
}

ll demTSNTPB(ll x){
    ll res = 0;
    while(x > 1){
        ll p = d[x];
        if(p == 0) p = x;
        while(x % p == 0){
            x /= p;
        }
        res += 1;
    }
    return res;
}

void distinct(){
    for(int i = 0; i < n; ++i){
        ll v = demTSNTPB(a[i]);
        if(v == k) cout << i + 1 << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DISTINCT.INP", "r", stdin);
    freopen("DISTINCT.OUT", "w", stdout);
    readData();
    sang();
    distinct();
    return 0;
}
