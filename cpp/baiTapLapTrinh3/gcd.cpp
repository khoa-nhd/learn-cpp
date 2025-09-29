#include <bits/stdc++.h>
using namespace std;
#define maxN 100000
typedef long long ll;

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void solve(){
    ll prefixgcd[maxN], suffixgcd[maxN];
    prefixgcd[0] = a[0];
    for(int i = 1; i < n; ++i){
        prefixgcd[i] = __gcd(prefixgcd[i-1], a[i]);
    }
    suffixgcd[n-1] = a[n-1];
    for(int i = n-2; i >= 0; --i){
        suffixgcd[i] = __gcd(suffixgcd[i+1], a[i]);
    }

    ll maxgcd;
    maxgcd = max(suffixgcd[1], prefixgcd[n-2]);
    int labaibo;
    if(suffixgcd[1] > prefixgcd[n-2]){
        labaibo = 1;
    } else{
        labaibo = n;
    }
    for(int i = 1; i < n-1; ++i){
        ll removei = __gcd(prefixgcd[i-1], suffixgcd[i+1]);
        if(removei > maxgcd){
            maxgcd = removei;
            labaibo = i + 1;
        }
    }
    cout << labaibo << " " << maxgcd;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GCD.INP", "r", stdin);
    freopen("GCD.OUT", "w", stdout);
    readData();
    solve();
    return 0;
}
