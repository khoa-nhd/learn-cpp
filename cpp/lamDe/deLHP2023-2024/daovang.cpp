#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll k, n;
ll a[maxN];

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

//ll daovang(){ đúng 40%
//    ll res = LLONG_MAX;
//    sort(a, a + n);
//    if(k == 1){
//        return a[n-1] - ((a[n-1] + a[0]) / 2);
//    } if(k == 2){
//        for(int i = 0; i < n; ++i){
//            ll mot = (a[i] + a[0]) / 2 - a[0];
//            ll hai = a[n-1] - (a[i+1] + a[n-1]) / 2;
//            ll temp = max(mot, hai);
//            res = min(res, temp);
//        }
//        return res;
//    }
//    return res;
//}

bool check(ll f){
    f *= 2;
    ll res = 1;
    ll bd = a[0];
    for(int i = 0; i < n; ++i){
        if(a[i] - bd > f){
            res += 1;
            bd = a[i];
        }
    }
    return res <= k;
}

ll daovang(){
    sort(a, a + n);
    ll res = 0;
    ll l = 1;
    ll h = 1e9;
    while(l <= h){
        ll half = (l + h) / 2;
        if(check(half)){
            h = half - 1;
            res = half;
        } else{
            l = half + 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    ll res;
    res = daovang();
    cout << res;
    return 0;
}
