#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
pair<ll, ll> a[1005];
bool ghe[1005] = {};
ll res[1005] = {};

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
       cin >> a[i].first >> a[i].second;
    }
}

void bai4(){
    for(int i = 0; i <= k; ++i){
        for(int j = 0; j < n; ++j){
            if(a[j].first == i){
                ll maxlen = LLONG_MIN;
                ll maxidx = -1;
                ll currlen = 0;
                ll curridx = 0;
                for(int l = 0; l <= k; ++l){
                    if(ghe[l]){
                        currlen = 0;
                        curridx = l + 1;
                    } else{
                        curridx += 1;
                        if(maxlen < currlen){
                            maxlen = currlen;
                            maxidx = curridx;
                        }
                    }
                }
                res[j] = maxidx + maxlen / 2;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        cout << res[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();
    bai4();
    return 0;
}
