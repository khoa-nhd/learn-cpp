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
    a = (a - k + 1) / k;
    b = (b - k + 1) / k;
    ll res = LLONG_MIN;
    for(int i = a; i <= b && i < n; ++i){
        res = max(res, arr[i]);
        if(i != 0) res = max(res, arr[n-i]);
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
