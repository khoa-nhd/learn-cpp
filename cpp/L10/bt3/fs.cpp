#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FS.INP", "r", stdin);
    freopen("FS.OUT", "w", stdout);
    ll area;
    cin >> area;
    for(ll i = 0; i * i <= area; ++i){
        ll j = area - i * i;
        ll sj = sqrt(j);
        if(sj * sj == j){
            cout << "0 0\n";
            cout << i << " " << sj << "\n";
            cout << sj + i << " " << -i + sj << "\n";
            cout << sj << " " << -i << "\n";
            return 0;
        }
    }
    cout << "Impossible";
    return 0;
}
