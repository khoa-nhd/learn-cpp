#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, q;
ll a[maxN];
ll pre[maxN] = {};

void readData(){
    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void sol(){
    pre[0] = 0;
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i-1] ^ a[i-1];
    }
    for(int i = 0; i < q; ++i){
        ll l, r;
        cin >> l >> r;
        cout << (pre[r] ^ pre[l-1]) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("XORDOAN.INP", "r", stdin);
    freopen("XORDOAN.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
