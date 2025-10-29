#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, m, a[maxN];

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll fm(){
    sort(a, a + n);
    ll l = 0, r = n - 1;
    ll res = 0;
    while(l <= r){
        if(a[l] + a[r] <= m){
            res = res + (r - l);
            l += 1;
        } else{
            r -= 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FM.INP", "r", stdin);
    freopen("FM.OUT", "w", stdout);
    readData();
    ll res;
    res = fm();
    cout << res;
    return 0;
}
