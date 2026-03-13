#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[1005] = {};
ll in[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> in[i];
    }
}

ll tohop(ll nn, ll k){
    if(nn == 0 || k > nn) return 0;
    if(k == 0 || k == nn) return 1;
    if(k > nn - k) k = nn - k;
    ll res = 1;
    for(int i = 1; i <= k; ++i){
        res = res * (nn - i + 1) / i;
    }
    return res;
}

ll btri(){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        ll x = in[i];
        for(int j = 0; j <= x / 2; ++j){
            int k = x - j;
            if(j * 2 == x){
                res += tohop(a[k], 2);
            } else res += a[j] * a[k];
        }
        if(x == 0){
            for(int i = 1; i <= 1000; ++i) res += tohop(a[i], 2);
        } else{
            for(int j = x + 1; j <= 1000; ++j){
                int k = j - x;
                res += a[j] * a[k];
            }
        }
        a[x] += 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BTRI.INP", "r", stdin);
    freopen("BTRI.OUT", "w", stdout);
    readData();
    ll res;
    res = btri();
    cout << res;
    return 0;
}
