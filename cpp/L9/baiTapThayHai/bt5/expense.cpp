#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 2005

ll t, n, m;
ll a[maxN] = {};

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll expense(){
    bool canBuy[maxN] = {};
    canBuy[0] = true;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(canBuy[j]){
                if(a[i] + j <= m){
                    canBuy[a[i] + j] = true;
                }
            }
        }
    }

    for(int i = m; i >= 0; --i){
        if(canBuy[i]) return i;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("EXPENSE.INP", "r", stdin);
    freopen("EXPENSE.OUT", "w", stdout);
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        ll res;
        res = expense();
        cout << res << "\n";
    }
    return 0;
}
