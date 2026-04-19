#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, a[maxN];
unordered_map<ll, ll> um;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll playlist(){
    ll r = 0, l = 0;
    ll res = 0;
    for(r; r < n; ++r){
        um[a[r]] += 1;
        while(um[a[r]] >= 2){
            um[a[l]] -= 1;
            l += 1;
        }
//        cout << l << " " << r << "\n";
        res = max(res, r - l + 1);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PLAYLIST.INP", "r", stdin);
    freopen("PLAYLIST.OUT", "w", stdout);
    readData();
    ll res;
    res = playlist();
    cout << res;
    return 0;
}
