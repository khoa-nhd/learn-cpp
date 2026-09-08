#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 105

ll n, arr[maxN];
ll a, b, k;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    cin >> a >> b >> k;
}

ll wheel(){
    a = (a-1) / k;
    b = (b-1) / k;
    ll res = LLONG_MIN;
    if(b - a > n){
        for(int i = 0; i < n; ++i) res = max(res, arr[i]);
        return res;
    }
    for(int i = a; i <= b; ++i){
        ll buoc = i % n;
        res = max(res, arr[buoc]);
        res = max(res, arr[(n-buoc)%n]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("WHEEL.INP", "r", stdin);
    freopen("WHEEL.OUT", "w", stdout);
    readData();
    ll res;
    res = wheel();
    cout << res;
    return 0;
}
