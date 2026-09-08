#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
vector<ll> a[35];
ll suf[35] = {};
ll res = LLONG_MIN;
ll cnt[35] = {};

void readData(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        ll num;
        cin >> num;
        for(int j = 0; j < num; ++j){
            ll temp;
            cin >> temp;
            a[i].push_back(temp);
        }
    }
}

void thue(ll i, ll curr){
    res = max(res, curr);
    if(i >= m) return;
    if(curr + suf[i] <= res) return;

    for(int j = 0; j < a[i].size(); ++j){
        cnt[a[i][j]] += 1;
    }
    bool valid = true;
    for(int j = 0; j < 34; ++j){
        if(cnt[j] > n){
            valid = false;
            break;
        }
    }
    curr += a[i].size();
    if(valid)thue(i+1, curr);
    for(int j = 0; j < a[i].size(); ++j){
        cnt[a[i][j]] -= 1;
    }
    curr -= a[i].size();

    thue(i+1, curr);
}

bool cmp(vector<ll> &x, vector<ll> &y){
    return x.size() > y.size();
}

void thuemay(){
    sort(a, a + m, cmp);
    for(int i = m - 1; i >= 0; --i){
        suf[i] = suf[i+1] + a[i].size();
    }
    thue(0, 0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("THUEMAY.INP", "r", stdin);
    freopen("THUEMAY.OUT", "w", stdout);
    readData();
    thuemay();
    cout << res;
    return 0;
}
