#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10000005

bool prime[maxN];
ll pre[maxN] = {};

void sang(){
    for(int i = 2; i < maxN; ++i) prime[i] = true;
    for(int i = 2; i * i < maxN; ++i){
        if(prime[i]){
            for(int j = i * i; j < maxN; j += i){
                prime[j] = false;
            }
        }
    }
}

bool check(ll x){
    ll mu10 = 10;
    while(mu10 < x){
        if((prime[x/mu10] && prime[x%mu10])) return true;
        mu10 *= 10;
    }
    return false;
}

void calPre(){
    for(int i = 10; i < maxN; ++i){
        if(prime[i] && check(i)){
            pre[i] = 1;
        }
    }
//    cout << pre[311] << pre[313] << pre[317] << "\n";
//    for(int i = 1; i < 100; ++i) cout << pre[i] << "\n";
    for(int i = 0; i < maxN; ++i){
        pre[i] += pre[i-1];
    }
//    cout << "\n";
//    for(int i = 1; i < 100; ++i) cout << pre[i] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    sang();
    calPre();
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l-1] << "\n";
    }
    return 0;
}
