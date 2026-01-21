#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> cnt(200);
ll n;

ll tongChuSo(ll x){
    ll res = 0;
    while(x > 0){
        res += x % 10;
        x /= 10;
    }
    return res;
}

ll numbers(){
    for(int i = 1; i < 1e6; ++i){
        cnt[tongChuSo(i)].push_back(i);
    }
    ll res = -1;
    for(int i = 0; i < cnt.size(); ++i){
        if(cnt[i].size() >= n){
            ll temp = 0;
            for(int j = 0; j < n; ++j){
                temp += cnt[i][j];
            }
            if(res == -1) res = temp;
            res = min(res, temp);
        }
    }
    return res;
}

int main(){
    freopen("NUMBERS.INP", "r", stdin);
    freopen("NUMBERS.OUT", "w", stdout);
    cin >> n;
    ll res = numbers();
    cout << res;
    return 0;
}
