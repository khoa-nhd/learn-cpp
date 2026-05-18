#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, s, m;
ll a[maxN];
ll arr[maxN];
ll prediff[maxN];

void readData(){
    cin >> n >> m >> s;
    for(int i = 0; i < m; ++i){
        cin >> a[i];
    }
}

ll sol(){
    sort(a, a + m);
    ll idx = 1;
    arr[0] = a[0];
    for(int i = 1; i < m; ++i){
        if(a[i] != a[i-1]){
            arr[idx++] = a[i];
        }
    }

    ll k = m - s;
    vector<pair<ll, ll>> res;
    for(int i = 0; i + k - 1 < idx; ++i){
        ll start = arr[i];
        ll endd = arr[i+k-1];
        if(endd - start <= m - 1){
            res.push_back({max(1LL, endd - m + 1), min(n-m+1, start)});
        }
    }

    if(res.size() == 0) return 0;
    ll ans = 0;
    ll currS = res[0].first, currE = res[0].second;
    for(int i = 1; i < res.size(); ++i){
        if(res[i].first <= currE){
            currE = res[i].second;
        } else{
            ans += currE - currS + 1;
            currS = res[i].first;
            currE = res[i].second;
        }
    }
    ans += currE - currS + 1;

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("HUB07.INP", "r", stdin);
    freopen("HUB07.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
