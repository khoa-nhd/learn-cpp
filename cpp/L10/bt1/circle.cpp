#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n;
pair<ll, ll> a[maxN], b[maxN];
ll da[maxN], db[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
        da[i] = a[i].first*a[i].first + a[i].second*a[i].second;
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i].first >> b[i].second;
        db[i] = b[i].first*b[i].first + b[i].second*b[i].second;
    }
}

ll cnt(ll arr[], ll target){
    ll d = 0, c = n-1;
    ll res = -1;
    while(d <= c){
        ll mid = (d + c) / 2;
        if(arr[mid] <= target){
            d = mid + 1;
            res = mid;
        } else c = mid - 1;
    }
    return res + 1;
}

double solve(){
    sort(da, da + n);
    sort(db, db + n);
    ll res = 1e18;
    for(int i = 0; i < n; ++i){
        if(cnt(db, da[i]) == cnt(da, da[i])){
            res = da[i];
//            cout << res << "\n";
            break;
        }
    }
    for(int i = 0; i < n; ++i){
        if(cnt(da, db[i]) == cnt(db, db[i])){
            res = min(res, db[i]);
//            cout << res << "\n";
            break;
        }
    }
//    for(int i = 0; i < n; ++i) cout << da[i] << " ";
//    cout << "\n";
//    for(int i = 0; i < n; ++i) cout << db[i] << " ";
//    cout << "\n";
//    cout << cnt(db, 4) << " " << cnt(da, 4) << "\n";
    double ans = sqrt(res);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CIRCLE.INP", "r", stdin);
    freopen("CIRCLE.OUT", "w", stdout);
    readData();
    double res = solve();
    cout << fixed << setprecision(6) << res;
    return 0;
}
