#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll m, n, k;
    cin >> m >> n >> k;
    if(m * n % 2 == 0){
        if(k == m * n / 2) cout << 2;
        else cout << 0;
    } else{
        if(k == m * n / 2 + 1 || k == m * n / 2) cout << 1;
        else cout << 0;
    }
    return 0;
}
