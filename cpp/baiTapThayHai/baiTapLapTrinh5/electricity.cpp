#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100000

ll n, k, a[maxN] = {};
bool coDien[maxN] = {};

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void setCoDien(ll i){
    for(int j = 0; j <= k; ++j){
        if(i + j < n){
            coDien[i+j] = true;
        }
        if(i - j >= 0){
            coDien[i-j] = true;
        }
    }
}

ll electricity(){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        if(!coDien[i]){
            ll best = -1;
            for(int j = 0; j <= k; ++j){
                if(i + j < n){
                    if(a[i+j] == 1) best = max(best, (ll)i+j);
                }
                if(i - j >= 0){
                    if(a[i-j] == 1) best = max(best, (ll)i-j);
                }
            }
            if(best == -1) return -1;
            setCoDien(best);
            res += 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ELECTRICITY.INP", "r", stdin);
    freopen("ELECTRICITY.OUT", "w", stdout);
    readData();
    k -= 1;
    ll res;
    res = electricity();
    cout << res;
    return 0;
}
