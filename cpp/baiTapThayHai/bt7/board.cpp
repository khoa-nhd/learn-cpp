#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

vector<ll> res;
ll n;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

void change(ll d, ll c, ll target){
    ll idx = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(res[half] <= target){
            idx = half;
            c = half - 1;
        } else{
            d = half + 1;
        }
    }
    if(idx != -1) res[idx] = target;
}

ll sol(){
    sort(a, a + n);
    for(int i = 0; i < n; ++i){
        if(res.size() == 0 || res.back() > a[i].second){
            res.push_back(a[i].second);
        } else{
            change(0, res.size() - 1, a[i].second);
        }
    }
    return res.size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BOARD.INP", "r", stdin);
    freopen("BOARD.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
