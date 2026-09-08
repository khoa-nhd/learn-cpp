#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[1005][1005], n, m;

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
}

void rsprial(){
    ll l = 0, r = m-1, t = 0, b = n-1;
    while(l <= r && t <= b){
        for(int i = l; i <= r; ++i) cout << a[t][i] << " ";
        for(int i = t + 1; i <= b; ++i) cout << a[i][r] << " ";
        if(t < b) for(int i = r - 1; i >= l; --i) cout << a[b][i] << " ";
        if(l < r) for(int i = b-1; i >= t + 1; --i) cout << a[i][l] << " ";
        r -= 1;
        b -= 1;
        l += 1;
        t += 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    rsprial();
    return 0;
}
