#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x1, y11, x2, y2, x3, y3, x4, y4;

ll intersec(){
    pair<ll, ll> tor1, tor2, bol1, bol2;
    tor1 = {max(x1, x2), max(y11, y2)};
    tor2 = {max(x3, x4), max(y3, y4)};
    bol1 = {min(x1, x2), min(y11, y2)};
    bol2 = {min(x3, x4), min(y3, y4)};
    if((tor1.first < bol2.first) || (tor2.first < bol1.first) ||
       (tor1.second < bol2.second) || (tor2.second < bol1.second)){
        return 0;
       }
    pair<ll, ll> oltr, olbl;
    oltr = {min(tor1.first, tor2.first), min(tor1.second, tor2.second)};
    olbl = {max(bol1.first, bol2.first), max(bol1.second, bol2.second)};
    ll chieuDai, chieuCao;
    chieuDai = oltr.first - olbl.first;
    chieuCao = oltr.second - olbl.second;
    return chieuCao*chieuDai;
}

int main(){
    freopen("INTERSEC.INP", "r", stdin);
    freopen("INTERSEC.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> x1 >> y11 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;
        ll res;
        res = intersec();
        cout << res << "\n";
    }
    return 0;
}
