#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

void sol(){
    map<ll, ll> mx, my;
    for(int i = 0; i < n; ++i){
        mx[a[i].first] += 1;
        my[a[i].second] += 1;
    }
    ll res = 0;
    for(int i = 0; i < n; ++i){
        res += (mx[a[i].first] - 1) * (my[a[i].second] - 1);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TRICOUNT.INP", "r", stdin);
    freopen("TRICOUNT.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
