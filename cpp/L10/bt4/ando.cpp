#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[maxN];
bitset<80> b[maxN];
bitset<1> dd[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void sol(){
    for(int i = 0; i < n; ++i) dd[i][0] = 1;
    for(int i = 0; i < n; ++i){
        ll t = a[i];
        for(int j = 0; j <= 30; ++j){
            if(t % 2 == 1) b[i][j] = 1;
            else b[i][j] = 0;
            t /= 2;
        }
    }
//    for(int i = 0; i < n; ++i){
//        for(int j = 0; j <= 30; ++j){
//            cout << b[i][j];
//        }
//        cout << "\n";
//    }
    for(int i = 30; i >= 0; --i){
        ll sl = 0;
        for(int j = 0; j < n; ++j){
            if(dd[j][0]){
                if(b[j][i]) sl += 1;
            }
        }
//        for(int j = 0; j < n; ++j){
//            cout << dd[j][0] << " ";
//        }
//        cout << "\n";
        if(sl >= 2){
            for(int j = 0; j < n; ++j){
                if(dd[j][0] && !b[j][i]) dd[j][0] = 0;
            }
        }
    }
    ll m = 0, h = 0;
    for(int i = 0; i < n; ++i){
        if(dd[i][0] && m == 0) m = a[i];
        else if(dd[i][0] && m > 0) h = a[i];
    }
    cout << (m & h);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ANDO.INP", "r", stdin);
    freopen("ANDO.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
