#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

ll films(){
    ll res = 1;
    sort(a, a + n, cmp);
    ll prev = a[0].second;
    for(int i = 0; i < n; ++i){
        if(a[i].first >= prev){
            prev = a[i].second;
            res += 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FILMS.INP", "r", stdin);
    freopen("FILMS.OUT", "w", stdout);
    readData();
    ll res = films();
    cout << res;
    return 0;
}
