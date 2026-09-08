#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
ll a[1000005];

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll pebbles(){
    sort(a, a + n);
    ll i = 1;
    ll res = 0;
    while(i < n){
        ll ngay = (a[i-1] + (k-1)) / k;
        res += ngay;
        a[i] -= ngay * k;
        if(a[i] <= 0) i += 1;
        i += 1;
    }
    res += (a[n-1] + (k*2-1)) / (k*2);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    ll res;
    res = pebbles();
    cout << res;
    return 0;
}
