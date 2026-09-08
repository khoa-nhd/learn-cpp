#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

bool checkPrime(ll x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; ++i){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUPPRIME.INP", "r", stdin);
    freopen("SUPPRIME.OUT", "w", stdout);
    cin >> n;
    ll mu10 = 10;
    while(mu10 < n){
        if(!checkPrime(n % mu10)){
            cout << "NO";
            return 0;
        }
        mu10 *= 10;
    }
    cout << "YES";
    return 0;
}
