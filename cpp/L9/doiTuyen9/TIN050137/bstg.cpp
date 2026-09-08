#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll tim(ll d, ll c, ll target){
    ll res = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(a[half] < target){
            res = half;
            d = half + 1;
        } else{
            c = half - 1;
        }
    }
    return res;
}

ll bstg(){
    sort(a, a + n);
    ll res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            ll idx = tim(j + 1, n-1, a[i] + a[j]);
            if(idx != -1){
                res += idx - j;
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BSTG.INP", "r", stdin);
    freopen("BSTG.OUT", "w", stdout);
    readData();
    ll res;
    res = bstg();
    cout << res;
    return 0;
}
