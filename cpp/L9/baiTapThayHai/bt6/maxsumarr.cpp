#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll t, n, a[maxN];
ll prefix[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll maxsumarr(){
    sort(a, a + n);
    prefix[0] = a[0];
    for(int i = 1; i < n; ++i){
        prefix[i] = prefix[i-1] + a[i];
    }
    ll maxx = a[0] * n;
    for(int i = 1; i < n; ++i){
        ll val = -prefix[i-1] + (n-i)*a[i];
        maxx = max(maxx, val);
    }
    return maxx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MAXSUMARR.INP", "r", stdin);
    freopen("MAXSUMARR.OUT", "w", stdout);
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        ll res;
        res = maxsumarr();
        cout << res << "\n";
    }
    return 0;
}
