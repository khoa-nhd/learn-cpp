#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, m, q;
ll a[maxN], ma[maxN];

void readData(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        ll l, r;
        cin >> l >> r;
        a[l] += 1;
        a[r+1] -= 1;
    }
    for(int i = 1; i <= n; ++i){
        a[i] += a[i-1];
    }
    for(int i = 1; i <= n; ++i){
        ma[a[i]] += 1;
    }
    for(int i = maxN-1; i >= 0; --i){
        ma[i] += ma[i+1];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PIGBANK.INP", "r", stdin);
    freopen("PIGBANK.OUT", "w", stdout);
    readData();
    cin >> q;
    for(int i = 0; i < q; ++i){
        ll t;
        cin >> t;
        cout << ma[t] << "\n";
    }
    return 0;
}
