#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[10];

void sol(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int ma = -1e9, mi = 1e9;
    for(int i = 0; i < n; ++i){
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }
    cout << ma - mi + 1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        sol();
    }
    return 0;
}
