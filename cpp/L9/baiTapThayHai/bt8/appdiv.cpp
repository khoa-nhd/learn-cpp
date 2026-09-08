#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[30];
ll res = LLONG_MAX;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void appdiv(ll i, ll sum1, ll sum2){
    if(i == n){
        res = min(res, abs(sum1 - sum2));
        return;
    }
    appdiv(i + 1, sum1 + a[i], sum2);
    appdiv(i + 1, sum1, sum2 + a[i]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("APPDIV.INP", "r", stdin);
    freopen("APPDIV.OUT", "w", stdout);
    readData();
    appdiv(0, 0, 0);
    cout << res;
    return 0;
}
