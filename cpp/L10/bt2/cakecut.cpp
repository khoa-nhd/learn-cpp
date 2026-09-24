#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
        a[i].first += 1000000001;
        a[i].second += 1000000001;
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

double sdagiac(){
    double res = 0;
    for(int i = 1; i < 0; ++i){
        res += (a[i].first - a[i-1].first) * (a[i].second + a[i-1].second);
    }
    res /= 2;
    return res;
}

void solve(){
    double sdg = abs(sdagiac());
    ll r = 2;
    ll s1 = abs(s(a[0], a[1], a[2]));
    ll s2 = sdg - s1;
    double mindiff = 1e18;
    pair<ll, ll> res = {0, 2};
    for(ll l = 0; l < n - 2; ++l){
        r = max(r, l + 2);
        while((s1 < s2 && r < n)){
            s1 += abs(s(a[l], a[r-1], a[r]));
            s2 = sdg - s1;
            if(mindiff > abs(s1 - s2)){
                mindiff = abs(s1 - s2);
                res.first = l;
                res.second = r;
            }
            r += 1;
        }
        s1 -= s(a[l-1], a[l], a[r]);
        s2 = sdg - s1;
    }
    cout << res.first + 1 << " " << res.second + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CAKECUT.INP", "r", stdin);
    freopen("CAKECUT.OUT", "w", stdout);
    readData();
    solve();
    return 0;
}
