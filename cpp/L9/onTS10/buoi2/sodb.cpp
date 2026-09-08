#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n;
bool prime[maxN] = {};
vector<ll> primes;

void sang(){
    for(int i = 2; i < maxN; ++i) prime[i] = true;
    for(int i = 2; i * i < maxN; ++i){
        if(prime[i]){
            for(int j = i * i; j < maxN; j += i){
                prime[j] = false;
            }
        }
    }
    for(int i = 0; i < maxN; ++i){
        if(prime[i]) primes.push_back(i);
    }
//    for(ll x : primes) cout << x << "\n";
}

ll sumNum(ll x){
    ll res = 0;
    while(x > 0){
        res += x%10;
        x /= 10;
    }
    return res;
}

ll sumtsnt(ll x){
    ll m = sqrt(x);
    int i = 0;
    ll res = 0;
    while(primes[i] <= m){
        while(x % primes[i] == 0){
            x /= primes[i];
            res += sumNum(primes[i]);
        }
        i += 1;
    }
    if(x > 1) res += sumNum(x);
    return res;
}

bool check(ll x){
    ll num = sumNum(x);
    ll numtsnt = sumtsnt(x);
    return num == numtsnt;
}

ll sodb(){
    ll i = n+1;
    while(true){
        if(check(i)) return i;
        i += 1;
    }
}

int main(){
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> n;
    sang();
    ll res;
    res = sodb();
    cout << res;
    return 0;
}
