#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll a[4], n;
ll cnt[maxN] = {};

void readData(){
    for(int i = 0; i < 4; ++i){
        cin >> a[i];
    }
    cin >> n;
}

ll atm(){
    ll res = 0;
    for(int i = 0; i <= n/50 && i <= a[3]; ++i){
        for(int j = 0; j <= n/5 && j <= a[0]; ++j){
            if(50*i+5*j <= n) cnt[50*i+5*j] += 1;
        }
    }
//    for(int i = 0; i <= 60; ++i) cout << cnt[i] << "\n";
    for(int i = 0; i <= n/20 && i <= a[2]; ++i){
        for(int j = 0; j <= n/10 && j <= a[1]; ++j){
            ll v = n - (20*i + 10*j);
            if(v >= 0) res += cnt[v];
        }
    }
    return res;
}

int main(){
    freopen("ATM.INP", "r", stdin);
    freopen("ATM.OUT", "w", stdout);
    readData();
    ll res;
    res = atm();
    cout << res;
    return 0;
}
