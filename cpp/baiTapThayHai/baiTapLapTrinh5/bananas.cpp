#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 205

ll t, n;
ll a[maxN][maxN];

void resetA(){
    for(int i = 0; i < maxN; ++i){
        for(int j = 0; j < maxN; ++j){
            a[i][j] = 0;
        }
    }
}

void readData(ll n){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n-i; ++j){
            cin >> a[i+n][j];
        }
    }
}

ll bananas(ll n){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            a[i][j] += max(a[i-1][j], a[i-1][j-1]);
//            cout << a[i][j] << " ";
        }
//        cout << "\n";
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n-i; ++j){
            a[i+n][j] += max(a[i+n-1][j], a[i+n-1][j+1]);
//            cout << a[i+n][j] << " ";
        }
//        cout << "\n";
    }
//    cout << "\n";
    return a[2*n - 1][1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BANANAS.INP", "r", stdin);
    freopen("BANANAS.OUT", "w", stdout);
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n;
        resetA();
        readData(n);
        ll res = bananas(n);
        cout << res << "\n";
//        cout << "\n";
    }
    return 0;
}
