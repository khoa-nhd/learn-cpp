#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, c;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n >> c;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first;
    }
    for(int i = 0; i < n; ++i){
        cin >> a[i].second;
    }
}

bool check(ll cl){
    ll maxx = LLONG_MIN;
    for(int l = 0; l < n; ++l){
        ll curr = a[l].second;
        ll r = l+1;
        while(a[r].first - a[r-1].first <= cl && r < n){
            curr += a[r].second;
            r += 1;
        }
        maxx = max(maxx, curr);
        l = r-1;
    }
    return maxx >= c;
}

ll credits(){
    sort(a, a + n);
    ll d = 0, c = 1e18;
    ll res = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(check(half)){
            res = half;
            c = half - 1;
        } else{
            d = half + 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CREDITS.INP", "r", stdin);
    freopen("CREDITS.OUT", "w", stdout);
    readData();
    ll res;
    res = credits();
    cout << res;
    return 0;
}
