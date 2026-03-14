#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll l, r;
bool prime[maxN] = {};

void sang(){
    for(int i = 2; i < maxN; ++i) prime[i] = true;
    for(int i = 2; i * i < maxN; ++i){
        if(prime[i]){
            for(int j = i * i ; j < maxN; j += i){
                prime[j] = false;
            }
        }
    }
}

bool checkPalind(ll x){
    ll c = x;
    ll y = 0;
    while(c > 0){
        y *= 10;
        y += c % 10;
        c /= 10;
    }
    return x == y;
}

ll tongchuso(ll x){
    ll res = 0;
    while(x > 0){
        res += x % 10;
        x /= 10;
    }
    return res;
}

ll sub1(){
    ll res = 0;
    for(int i = l; i <= r; ++i){
        if(prime[tongchuso(i)] && checkPalind(i)){
            res += 1;
        }
    }
    return res;
}

ll nhap(ll x, ll y){
    ll res = x;
    while(y > 0){
        res *= 10;
        res += y % 10;
        y /= 10;
    }
    return res;
}

ll sub2(){
    ll res = 0;
    for(int i = 1; i < 1e7; ++i){
        ll j = nhap(i, i);
        if(j > r) break;
        if(l <= j && j <= r){
            if(prime[tongchuso(j)]) res += 1;
        }
        for(int k = 0; k <= 9; ++k){
            ll e = nhap(i*10+k, i);
            if(l <= e && e <= r){
                if(prime[tongchuso(e)]) res += 1;
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PALINPRIME.INP", "r", stdin);
    freopen("PALINPRIME.OUT", "w", stdout);
    sang();
    cin >> l >> r;
    ll res;
    if(r <= 1e6){
        res = sub1();
    } else{
        res = sub2();
    }
    cout << res;
    return 0;
}
