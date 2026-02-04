#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

bool prime[maxN] = {};
vector<ll> primes;

void sangNguyenTo(){
    for(int i = 2; i < maxN; ++i) prime[i] = true;
    for(int i = 0; i * i < maxN; ++i){
        if(prime[i]){
            for(int j = i * i; j <= maxN; j += i){
                prime[j] = false;
            }
        }
    }
    prime[2] = false;
    for(int i = 0; i < maxN; ++i){
        if(prime[i]) primes.push_back(i);
    }
}

ll goldbach(ll n){
    ll res = 1;
    for(int i = 3; i <= 2*n; ++i){
        if(prime[i]){
            auto it = upper_bound(primes.begin(), primes.end(), min((ll)i, 2*n - i));
            if(it != primes.end()){
                ll idx = it - primes.begin();
                res += idx;
            }
        }
    }
    return res;
}

int main(){
    freopen("GOLDBACH.INP", "r", stdin);
    freopen("GOLDBACH.OUT", "w", stdout);
    ll n;
    sangNguyenTo();
    while(cin >> n){
        ll res;
        res = goldbach(n);
        cout << res << "\n";
    }
    return 0;
}
