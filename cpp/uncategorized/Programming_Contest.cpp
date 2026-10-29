#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, t;
ll a[45];
vector<ll> v;
ll res = 0;

void readData(){
    cin >> n >> t;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void nuaDau(ll i, ll sum){
    if(i == n/2){
        v.push_back(sum);
        return;
    }
    nuaDau(i+1, sum);
    if (sum + a[i] <= t) nuaDau(i+1, sum + a[i]);
}

void nuaSau(ll i, ll sum){
    if(i == n){
        ll target = t - sum;
        auto it = upper_bound(v.begin(), v.end(), target);
        res = max(res, sum + *(--it));
//        cout << sum << " " << target << " " << it - v.begin() << " " << res << "\n";
        return;
    }
    nuaSau(i+1, sum);
    if (sum + a[i] <= t) nuaSau(i+1, sum + a[i]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    nuaDau(0, 0);
    sort(v.begin(), v.end());
//    for(ll x : v) cout << x << " ";
//    cout << "\n";
    nuaSau(n/2, 0);
    cout << res;
    return 0;
}
