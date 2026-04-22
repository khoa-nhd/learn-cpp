#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10005

ll n, a[maxN];
ll dp[maxN] = {};
bool take[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

void bottles(){
    for(int i = 0; i <= n; ++i) take[i] = true;
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    for(int i = 3; i <= n; ++i){
        ll mot = dp[i-1];
        ll hai = dp[i-2] + a[i];
        ll ba = dp[i-3] + a[i-1] + a[i];
        if(mot > hai && mot > ba){
            dp[i] = mot;
            take[i] = false;
        } else if(hai > mot && hai > ba){
            dp[i] = hai;
            take[i-1] = false;
        } else{
            dp[i] = ba;
            take[i-2] = false;
        }
    }
    vector<ll> res;
    for(int i = 1; i <= n; ++i){
        if(take[i]) res.push_back(i);
    }
    cout << res.size() << " " << dp[n] << "\n";
    for(ll x : res) cout << x << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BOTTLES.INP", "r", stdin);
    freopen("BOTTLES.OUT", "w", stdout);
    readData();
    bottles();
    return 0;
}
