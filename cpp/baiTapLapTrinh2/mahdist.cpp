#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<pair<ll, ll>> a;

void readData(){
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

ll mahdist(){
    ll u, v;
    ll maxv = a[0].first - a[0].second;
    ll minv = maxv;
    ll maxu = a[0].first + a[0].second;
    ll minu = maxu;

    for(int i = 1; i < n; ++i){
        u = a[i].first + a[i].second;
        v = a[i].first - a[i].second;

        maxv = maxv < v ? v : maxv;
        minv = minv > v ? v : minv;
        maxu = maxu < u ? u : maxu;
        minu = minu > u ? u : minu;
    }

    return max(abs(maxv - minv), abs(maxu - minu));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MAHDIST.INP", "r", stdin);
    freopen("MAHDIST.OUT", "w", stdout);
    readData();
    ll result;
    result = mahdist();
    cout << result;
    return 0;
}
