#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define maxN 1000005

ll n;
ll d[maxN] = {};
ll thuaSoNguyenTo[maxN] = {};
ll soMod = 1e9 + 7;

void sang(){
    for(int i = 2; i < maxN; ++i){
        if(d[i] == 0){
            for(int j = i; j < maxN; j += i){
                d[j] = i;
            }
        }
    }
}

void phantich(ll x){
    while(x > 1){
        ll p = d[x];
        if(p == 0) p = x;
        ll cnt = 0;
        while(x % p == 0){
            cnt += 1;
            x /= p;
        }
        thuaSoNguyenTo[p] = max(thuaSoNguyenTo[p], cnt);
    }
}

ull muMod(ll base, ll power){
    if(power == 0) return 1;
    base %= soMod;
    ull temp = muMod(base, power/2);
    temp *= temp;
    temp %= soMod;
    if(power % 2 == 0) return temp;
    return (temp * base) % soMod;
}

ull lcm(){
    for(int i = 1; i <= n; ++i) phantich(i);
//    for(int i = 0; i < 10; ++i){
//        cout << thuaSoNguyenTo[i] << "\n";
//    }
    ull res = 1;
    for(int i = 2; i < maxN; ++i){
        res *= muMod(i, thuaSoNguyenTo[i]);
        res %= soMod;
    }
    return res;
}

int main(){
    freopen("LCM.INP", "r", stdin);
    freopen("LCM.OUT", "w", stdout);
    cin >> n;
    sang();
    ull res = 0;
    res = lcm();
    cout << res;
    return 0;
}
