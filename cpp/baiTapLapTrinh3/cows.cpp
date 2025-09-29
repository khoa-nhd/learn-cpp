#include <bits/stdc++.h>
using namespace std;
#define maxN 100000
typedef long long ll;

pair<ll, ll> a[maxN];
ll n;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b){
    ll x = 2*a.first*b.second, y = 2*b.first*a.second;
    return x < y;
}

ll cows(){
    ll result = 0;
    sort(a, a + n, cmp);
    ll thoigiancho = 0;
    for(int i = 1; i < n; ++i){
        thoigiancho += 2*a[i-1].first;
        result += thoigiancho*a[i].second;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("COWS.INP", "r", stdin);
    freopen("COWS.OUT", "w", stdout);
    readData();
    ll m;
    m = cows();
    cout << m;
    return 0;
}
