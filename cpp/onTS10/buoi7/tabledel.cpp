#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, m, k;
ll cot[maxN] = {};
ll dong[maxN] = {};

void readData(){
    cin >> n >> m >> k;
    for(int i = 0; i < k; ++i){
        ll x, y;
        cin >> x >> y;
        dong[x] += 1;
        cot[y] += 1;
    }
}

ll tabledel(){
    ll res = 0;
    ll c = 0, d = 0;
    for(int i = 1; i <= m; ++i){
//        cout << cot[i] << " ";
        if(cot[i] == 0){
            res += n;
            c += 1;
        }
    }
//    cout << "\n";
    for(int i = 1; i <= n; ++i){
//        cout << dong[i] << " ";
        if(dong[i] == 0){
           res += m;
           d += 1;
        }
    }
//    cout << "\n";
    res -= c * d;
    res = n * m - res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    ll res;
    res = tabledel();
    cout << res;
    return 0;
}
