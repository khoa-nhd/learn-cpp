#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n,  m;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

//ll giaohang(){ sai hết rồi
//    ll maxLay = LLONG_MIN;
//    ll minGiao = LLONG_MAX;
//    for(int i = 0; i < n; ++i){
//        if(a[i].first > a[i].second){
//            maxLay = max(maxLay, a[i].first);
//            minGiao = min(minGiao, a[i].second);
//        }
//    }
//    ll res;
//    if(maxLay == LLONG_MIN) res = m;
//    else res = maxLay + (maxLay - minGiao) + (m - minGiao);
//
//    return res;
//}

ll giaohang(){
    vector<pair<ll, ll>> b;
    for(int i = 0; i < n; ++i){
        if(a[i].first > a[i].second){
            b.push_back({a[i].second, a[i].first});
        }
    }
    sort(b.begin(), b.end());
    if(b.size() == 0) return m;
    ll res = m;
    ll bd = b[0].first;
    ll kt = b[0].second;
    for(int i = 1; i < b.size(); ++i){
        if(b[i].first <= kt){
            kt = max(kt, b[i].second);
        } else{
            res += (kt - bd) * 2;
            bd = b[i].first;
            kt = b[i].second;
        }
    }
    res += (kt - bd) * 2;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    ll res;
    res = giaohang();
    cout << res;
    return 0;
}
