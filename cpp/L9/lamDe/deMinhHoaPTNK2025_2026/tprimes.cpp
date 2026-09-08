#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 2000000

ll n, k;
ll x = 0;
bool prime[maxN] = {};
vector<ll> primes;
ll res = 0;

void sang(){
    for(int i = 2; i < maxN; ++i) prime[i] = true;
    for(ll i = 2; i * i < maxN; ++i){
        if(prime[i]){
            for(ll j = i * i; j < maxN; j += i){
                prime[j] = false;
            }
        }
    }
    for(int i = 0; i < maxN; ++i){
        if(prime[i]){
            primes.push_back(i);
        }
    }
//    for(int i = 0; i < 100; ++i){
//        cout << primes[i] << "\n";
//    }
}

ll mu(ll base, ll power){
    if(power == 0) return 1;
    ll temp = mu(base, power / 2);
    if(temp == -1) return -1;
    if(temp > n / temp) return -1;
    else temp *= temp;
    if(power % 2 == 0) return temp;
    else{
        if(temp > n / base) return -1;
        else return temp * base;
    }
}

//ll findmax(ll idx){ sai vì không cố định bộ ba số mũ
//    ll res = -1;
//    for(int t1 = 1; t1 <= k/4; ++t1){
//        for(int t2 = 1; t2 <= k/4; ++t2){
//            ll x = mu(primes[idx], t1);
//            if(x == -1) return res;
//            ll y = mu(primes[idx+1], t2);
//            if(y == -1) break;
//            if(k % ((t1+1)*(t2+1)) != 0) break;
//            int t3 = k / ((t1+1)*(t2+1)) - 1;
//            ll z = mu(primes[idx+2], t3);
//            if(z == -1) continue;
//            if(x <= n/y){
//                if(z <= n / (x * y)){
//                    res = max(res, x * y * z);
//                }
//            }
//        }
//    }
//    return res;
//}
//
//ll sol(){
//    ll d = 0, c = primes.size() - 5;
//    ll res = -1;
//    while(d <= c){
//        ll half = (d + c) / 2;
//        ll v = findmax(half);
//        if(v == -1){
//            c = half - 1;
//        } else{
//            res = max(v, res);
//            d = half + 1;
//        }
//    }
//    return res;
//}

ll findmax(int t1, int t2, int t3){
    ll res = -1;
    ll d = 0, c = primes.size() - 5;
    while(d <= c){
        ll half = (d + c) / 2;
        ll x = mu(primes[half], t1);
        ll y = mu(primes[half+1], t2);
        ll z = mu(primes[half+2], t3);
        if(x != -1 && y != -1 && z != -1 && x <= n / y && z <= n / (y * x)){
            res = x * y * z;
            d = half + 1;
        } else{
            c = half - 1;
        }
    }
    return res;
}

void sol(){
    ll res = 0;
    for(int t1 = 1; t1 <= k / 4; ++t1){
        for(int t2 = 1; t2 <= k / 4; ++t2){
            if(k % ((t1+1) * (t2+1)) != 0) continue;
            int t3 = k / ((t1+1) * (t2+1)) - 1;
            if(t3 < 1) continue;
            ll v = findmax(t1, t2, t3);
            if(v == -1) continue;
            res = max(res, v);
        }
    }
    cout << res;
}

int main(){
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> n >> k;
    sang();
    sol();
    return 0;
}
