#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll t;
pair<ll, ll> a[maxN];
bool prime[maxN];
vector<ll> primes;
vector<ll> high;
ll prefix[maxN] = {};

void sang(){
    for(int i = 2; i < maxN; ++i) prime[i] = true;
    for(int i = 2; i * i < maxN; ++i){
        if(prime[i]){
            for(int j = i * i; j < maxN; j += i){
                prime[j] = false;
            }
        }
    }
    for(int i = 2; i < maxN; ++i){
        if(prime[i]){
            primes.push_back(i);
        }
    }
}

ll mu(ll base, ll power){
    if(power == 0) return 1;
    ll temp = mu(base, power/2);
    temp *= temp;
    if(power % 2 == 0) return temp;
    else return base * temp;
}

void lowab(){
    for(int i = 0; i < primes.size(); ++i){
        for(int j = 0; j < primes.size(); ++j){
            ll v = mu(primes[i], primes[j]-1);
            if(v > maxN) break;
            prefix[v] += 1;
        }
    }
    for(int i = 1; i < maxN; ++i){
        prefix[i] += prefix[i-1];
    }
}

void highab(){
    for(int i = 0; i < primes.size(); ++i){
        for(int j = 1; j < primes.size(); ++j){
            ll v = mu(primes[i], primes[j]-1);
            if(v > 1e12) break;
            if(v > 1e6) high.push_back(v);
        }
    }
    sort(high.begin(), high.end());
}

void cprime(){
    lowab();
    highab();
    cin >> t;
    ll a, b;
    for(int i = 0; i < t; ++i){
        cin >> a >> b;
        if(a <= 1e6){
            cout << prefix[b] - prefix[a-1] << "\n";
        } else{
            auto itb = upper_bound(high.begin(), high.end(), b);
            auto ita = lower_bound(high.begin(), high.end(), a);
            cout << itb - ita << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CPRIME.INP", "r", stdin);
    freopen("CPRIME.OUT", "w", stdout);
    sang();
    cprime();
    return 0;
}
