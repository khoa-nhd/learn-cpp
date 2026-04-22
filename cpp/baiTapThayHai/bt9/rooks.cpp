#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, k;
char bang[105][105] = {};

void rooks(){
    ll a = min(n, m);
    if(k > a){
        cout << "Impossible";
        return;
    }
    cout << "Possible\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            bang[i][j] = '.';
        }
    }
    for(int i = 0; i < k; ++i){
        bang[i][i] = '*';
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << bang[i][j];
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ROOKS.INP", "r", stdin);
    freopen("ROOKS.OUT", "w", stdout);
    cin >> n >> m >> k;
    rooks();
    return 0;
}
