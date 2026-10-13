#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

pair<ll, ll> a[maxN];
ll n = 0;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
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
    for(int i = 0; i < n; ++i){
        while(v.size() >= 2 && s(v[v.size()-2], v.back(), a[i]) <= 0){
            v.pop_back();
        }
        v.push_back(a[i]);
    }
    return v;
}

void dtdg(vector<pair<ll, ll>> &dg){
    double res = 0;
    dg.push_back(dg[0]);
    for(int i = 0; i < dg.size()-1; ++i){
        ll x1 = dg[i].first; ll y1 = dg[i].second;
        ll x2 = dg[i+1].first; ll y2 = dg[i+1].second;
        res += (y1 + y2) * (x2 - x1);
    }
    dg.pop_back();
    res /= 2;
    res = abs(res);
    cout << fixed << setprecision(1) << res << "\n";
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
    cout << res.size() << "\n";
    dtdg(res);
    int start_idx = 0;
    for(int i = 1; i < res.size(); ++i){
        if(res[i].second < res[start_idx].second ||
          (res[i].second == res[start_idx].second && res[i].first < res[start_idx].first)){
            start_idx = i;
        }
    }
    for(int i = 0; i < res.size(); ++i){
        int idx = (start_idx + i) % res.size();
        cout << res[idx].first << " " << res[idx].second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CONVEXHULL.INP", "r", stdin);
    freopen("CONVEXHULL.OUT", "w", stdout);
    readData();
    solve();
    return 0;
}
