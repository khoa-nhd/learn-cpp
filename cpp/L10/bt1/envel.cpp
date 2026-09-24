#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

pair<ll, ll> a[maxN];
ll n = 0;
vector<pair<ll, ll>> res;

void readData(){
    ll x, y;
    while(cin >> x >> y){
        a[n].first = x;
        a[n].second = y;
        n += 1;
    }
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

void solve(){
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
    solve();
    return 0;
}


/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

pair<ll, ll> a[maxN];
ll n = 0;

void readData(){
    ll x, y;
    while(cin >> x >> y){
        a[n].first = x;
        a[n].second = y;
        n += 1;
    }
}

double s(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){
    double res = 0;
    res += (c.second + a.second) * (a.first - c.first);
    res += (a.second + b.second) * (b.first - a.first);
    res -= (b.second + c.second) * (b.first - c.first);
    res /= 2;
    return res;
}

bool cmp(pair<ll, ll> x, pair<ll, ll> y){
    if(x.first == y.first) return x.second < y.second;
    return x.first < y.first;
}

bool cmp2(pair<ll, ll> x, pair<ll, ll> y){
    if(x.first == y.first) return x.second > y.second;
    return x.first > y.first;
}

vector<pair<ll, ll>> tim(){
    vector<pair<ll, ll>> v;
    v.push_back(a[0]);
    v.push_back(a[1]);
    ll i = 2;
    while(i < n){
        if(s(v[v.size()-2], v.back(), a[i]) > 0){
            v.push_back(a[i]);
            i += 1;
        } else{
            v.pop_back();
        }
    }
    return v;
}

void solve(){
    vector<pair<ll, ll>> res;
    sort(a, a + n, cmp);
    vector<pair<ll, ll>> v = tim();
    for(int i = 0; i < v.size() - 1; ++i) res.push_back(v[i]);
    sort(a, a + n, cmp2);
    v = tim();
    for(int i = 0; i < v.size() - 1; ++i) res.push_back(v[i]);
    reverse(res.begin(), res.end());
    for(pair<ll, ll> x : res){
        cout << x.first << " " << x.second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ENVEL.INP", "r", stdin);
    freopen("ENVEL.OUT", "w", stdout);
    readData();
    solve();
    return 0;
}*/
