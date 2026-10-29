#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, m;
ll a[maxN];

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void sol(){
    ll tong = 0;
    for(int i = 0; i < n; ++i){
        tong += a[i];
    }
    if(tong % m == 0) cout << "YES";
    else cout << "NO";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SHARE.INP", "r", stdin);
    freopen("SHARE.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
