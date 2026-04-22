#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n, p, q;
string a[1005], b[1005];

void readData(){
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        cin >> a[i];
    }
    cin >> p >> q;
    for(int i = 0; i < p; ++i){
        cin >> b[i];
    }
}

bool grid(){
    for(int i = 0; i + p <= m; ++i){
        for(int j = 0; j + q <= n; ++j){
            string sub = a[i].substr(j, q);
            if(sub == b[0]){
                for(int k = 1; k < p; ++k){
                    string sub2 = a[i+k].substr(j, q);
                    if(sub2 != b[k]) break;
                    if(k == p-1) return true;
                }
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GRID.INP", "r", stdin);
    freopen("GRID.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        bool res;
        res = grid();
        if(res) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}
