#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll a[105][105];

void sol(){
    ll maxx = n*n;
    ll val = 1;
    ll l = 0, r = n-1, t = 0, b = n-1;
    while(val <= maxx){
        for(int i = l; i <= r && val <= maxx; ++i){
            a[t][i] = val;
            val += 1;
        }
        if(val > maxx) break;

        for(int i = t + 1; i <= b && val <= maxx; ++i){
            a[i][r] = val;
            val += 1;
        }
        if(val > maxx) break;

        for(int i = r - 1; i >= l && val <= maxx; --i){
            a[b][i] = val;
            val += 1;
        }
        if(val > maxx) break;

        for(int i = b-1; i >= t + 1 && val <= maxx; --i){
            a[i][l] = val;
            val += 1;
        }
        if(val > maxx) break;

        l += 1;
        b -= 1;
        t += 1;
        r -= 1;
    }
}

void output(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> n;
    sol();
    output();
    return 0;
}
