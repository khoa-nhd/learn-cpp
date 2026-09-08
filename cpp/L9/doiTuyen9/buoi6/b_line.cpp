#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, m, cnt[maxN] = {};
ll k;

void readData(){
    cin >> m >> n >> k;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            ll temp;
            cin >> temp;
            cnt[temp] += 1;
//            cout << temp << "\n";
        }
    }
}

ll b_line(){
    vector<ll> v;
    for(int i = 0; i < maxN; ++i){
        v.push_back(cnt[i]);
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll res = 0;
    for(int i = 0; i < k; ++i){
        res += v[i];
//        cout << v[i] << " ";
    }
//    cout << "\n";
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    ll res;
    res = b_line();
    cout << res;
    return 0;
}
