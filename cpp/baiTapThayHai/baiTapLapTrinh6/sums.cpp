#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void sums(){
    ll s = -1;
    ll len = 2;
    ll loop = sqrt(2*n) + 1;
    for(len; len < loop; ++len){
        ll bd = ((2*n)/len - len + 1) / 2;
        if(len * (2 * bd + len - 1) == 2 * n){
            s = bd;
            break;
        }
    }
    if(s == -1){
        cout << "IMPOSSIBLE" << "\n";
        return;
    }
    cout << n << " = ";
    for(int i = 0; i < len - 1; ++i){
        cout << s << " + ";
        s += 1;
    }
    cout << s << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUMS.INP", "r", stdin);
    freopen("SUMS.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n;
        sums();
    }
    return 0;
}
