#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void sol(){
    ll xorall = 0;
    for(int i = 0; i < n; ++i){
        xorall = xorall ^ a[i];
    }
    ll lowbit = xorall & -xorall;
    ll u = 0, v = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] & lowbit) u = u ^ a[i];
        else v = v ^ a[i];
    }
    cout << min(u, v) << " " << max(u, v);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("HAILELOI.INP", "r", stdin);
    freopen("HAILELOI.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
