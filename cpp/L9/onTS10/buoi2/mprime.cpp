#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll k;
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

ll ghep(ll x, ll y){
    ll ry = 0;
    while(y > 0){
        ry *= 10;
        ry += y % 10;
        y /= 10;
    }
    while(ry > 0){
        x *= 10;
        x += ry % 10;
        ry /= 10;
    }
    return x;
}

bool checkPrime(ll x){
    if(x < 2) return false;
    if(x < 4) return true;
    if(x % 2 == 0 || x % 3 == 0) return false;
    ll m = sqrt(x);
    for(ll i = 5; i < m; i += 6){
        if(x % i == 0 || x % (i+2) == 0) return false;
    }
    return true;
}

ll mprime(){
    for(int i = 1; i < primes.size(); i += 2){
        ll v = ghep(primes[i-1], primes[i]);
        if(checkPrime(v)) k -= 1;
        if(k == 0) return v;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> k;
    sang();
    ll res;
    res = mprime();
    cout << res;
    return 0;
}
