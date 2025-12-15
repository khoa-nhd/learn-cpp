#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 2000005

ll x[maxN], y[maxN];
ll m, n, k;

void readData(){
    cin >> m >> n >> k;
    for(int i = 0; i < 4*k; ++i){
        cin >> x[i] >> y[i];
    }
}

ll sol(){
    nth_element(x, x + 2*k, x + 4*k);
    nth_element(x, x + 2*k - 1, x + 4*k);
    nth_element(y, y + 2*k, y + 4*k);
    nth_element(y, y + 2*k - 1, y + 4*k);
    ll half = 2*k;
    return (x[half] - x[half-1]) * (y[half] - y[half-1]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CAKE.INP", "r", stdin);
    freopen("CAKE.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
