#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

bool prime[maxN] = {};
vector<ll> primes;
ll n, k;

void sangNguyenTo(){
    for(int i = 2; i <= n; ++i) prime[i] = true;
    ll loop = sqrt(n);
    for(int i = 2; i <= loop; ++i){
        if(prime[i]){
            for(int j = i * i; j <= n; j += i){
                prime[j] = false;
            }
        }
    }

    for(int i = 2; i <= n; ++i){
        if(prime[i]) primes.push_back(i);
    }

//    for(ll x : primes) cout << x << " ";
//    cout << "\n";
}

void pairs(){
    if(k == 1){
        cout << "1 1";
        return;
    }
    ll stt = 0;
    ll m = primes.size();
    for(int i = 1; i <= n/2; ++i){
        auto it = lower_bound(primes.begin(), primes.end(), 2*i);
        ll j = it - primes.begin();
        if(m - j >= k){
            cout << i << " " << primes[j+k-1] - i;
            return;
        }
        k -= m - j;
    }
    cout << "-1 -1";
}

int main(){
    freopen("PAIRS.INP", "r", stdin);
    freopen("PAIRS.OUT", "w", stdout);
    cin >> n >> k;
    sangNguyenTo();
    pairs();
    return 0;
}
