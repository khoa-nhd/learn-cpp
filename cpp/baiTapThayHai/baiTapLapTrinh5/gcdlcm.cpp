#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define maxN 1000005

ll m, n, a[maxN], b[maxN];
ll pfA[maxN] = {};
ll pfB[maxN] = {};
ll d[maxN] = {};
ll soMod = 1e9 + 7;

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> b[i];
    }
}

void sangMoRong(){
    for(int i = 2; i * i < maxN; ++i){
        if(d[i] == 0){
            for(int j = i; j*i < maxN; ++j){
                d[i*j] = i;
            }
        }
    }
}

void phanTich(ll x, ll pf[]){
    ll p;
    while(x > 1){
        p = d[x];
        if(p == 0) p = x;
        while(x % p == 0){
            x /= p;
            pf[p] += 1;
        }
    }
}

void primeFactors(){
    for(int i = 0; i < n; ++i){
        phanTich(a[i], pfA);
    }
    for(int i = 0; i < m; ++i){
        phanTich(b[i], pfB);
    }
}

ull muMod(ull base, ull power){
    if(power == 0) return 1;
    ull res = muMod(base, power/2);
    ull temp = (res * res) % soMod;
    if(power % 2LL == 1) return (temp * base) % soMod;
    else return temp;
}

ll ucln(){
    ll res = 1;
    for(int i = 2; i < maxN; ++i){
        if(pfA[i] > 0 && pfB[i] > 0){
            res = (res * muMod(i, min(pfA[i], pfB[i]))) % soMod;
        }
    }
    return res;
}

ll bcnn(){
    ll res = 1;
    for(int i = 2; i < maxN; ++i){
        if(pfA[i] > 0 || pfB[i] > 0){
            res = (res * muMod(i, max(pfA[i], pfB[i]))) % soMod;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GCDLCM.INP", "r", stdin);
    freopen("GCDLCM.OUT", "w", stdout);
    sangMoRong();
    readData();
    primeFactors();
    ll res1 = ucln();
    ll res2 = bcnn();
    cout << res1 << "\n" << res2;
    return 0;
}
