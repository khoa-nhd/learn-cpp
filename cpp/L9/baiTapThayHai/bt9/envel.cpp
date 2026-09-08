#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

pair<ll, ll> a[maxN];
ll n;
vector<pair<ll, ll>> res;

void readData(){
    ll x, y;
    ll i = 0;
    while(cin >> x >> y){
        a[i].first = x;
        a[i].second = y;
        i += 1;
    }
    n = i;
}

void solx(ll x, ll c, ll loai){
    ll y = (loai == 1) ? (c - x) : (x - c);
    pair<ll, ll> temp = {x, y};
    if(res.size() == 0 || temp != res.back()) res.push_back(temp);
}

void soly(ll y, ll c, ll loai){
    ll x = (loai == 1) ? (c - y) : (c + y);
    pair<ll, ll> temp = {x, y};
    if(res.size() == 0 || temp != res.back()) res.push_back(temp);
}

void envil(){
    ll minx = LLONG_MAX, maxx = LLONG_MIN;
    ll miny = LLONG_MAX, maxy = LLONG_MIN;
    ll mincc = LLONG_MAX, maxcc = LLONG_MIN;
    ll mincp = LLONG_MAX, maxcp = LLONG_MIN;
    for(int i = 0; i < n; ++i){
        minx = min(minx, a[i].first); maxx = max(maxx, a[i].first);
        miny = min(miny, a[i].second); maxy = max(maxy, a[i].second);
        mincc = min(mincc, a[i].first + a[i].second); maxcc = max(maxcc, a[i].first + a[i].second);
        mincp = min(mincp, a[i].first - a[i].second); maxcp = max(maxcp, a[i].first - a[i].second);
    }
    soly(miny, maxcp, 2);
    solx(maxx, maxcp, 2);
    solx(maxx, maxcc, 1);
    soly(maxy, maxcc, 1);
    soly(maxy, mincp, 2);
    solx(minx, mincp, 2);
    solx(minx, mincc, 1);
    soly(miny, mincc, 1);
    if(res.size() > 1 && res.back() == res.front()) res.pop_back();

    for(pair<ll, ll> x : res) cout << x.first << " " << x.second << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ENVEL.INP", "r", stdin);
    freopen("ENVEL.OUT", "w", stdout);
    readData();
    envil();
    return 0;
}
