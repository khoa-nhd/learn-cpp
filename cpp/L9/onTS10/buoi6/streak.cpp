#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a[100];
ll b[100] = {};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        if(a[i] == a[i-1]) b[i] = b[i-1] + 1;
        else b[i] = 1;
    }
    ll x = 0, y = 0;
    for(int i = 1; i <= n; ++i){
        if(a[i][0] == 'H') x = max(x, b[i]);
        else y = max(y, b[i]);
    }
    cout << x << " " << y;
    return 0;
}
