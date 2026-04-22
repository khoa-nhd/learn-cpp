#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[500][500];
ll soCC[500][500], soCP[500][500];
ll pCC[1005][500] = {}, pCP[1005][500] = {};

void readData(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
}

void prefixSum1(){
    ll num = 1;
    for(int k = n; k >= 1; --k){
        ll i = k;
        ll j = 1;
        while(i <= n && j <= n){
            pCC[num][j] = pCC[num][j-1] + a[i][j];
//            cout << pCC[num][j] << " ";
            soCC[i][j] = num;
            i += 1;
            j += 1;
        }
//        cout << "\n";
        num += 1;
    }
    for(int k = 2; k <= n; ++k){
        ll i = 1;
        ll j = k;
        while(i <= n && j <= n){
            pCC[num][i] = pCC[num][i-1] + a[i][j];
//            cout << pCC[num][i] << " ";
            soCC[i][j] = num;
            i += 1;
            j += 1;
        }
//        cout << "\n";
        num += 1;
    }
//    cout << "\n";
}

void prefixSum2(){
    ll num = 1;
    for(int k = n; k >= 1; --k){
        ll i = k;
        ll j = n;
        while(i <= n && j >= 1){
            pCP[num][n-j+1] = pCP[num][n-j] + a[i][j];
//            cout << pCP[num][n-j+1] << " ";
            soCP[i][j] = num;
            i += 1;
            j -= 1;
        }
//        cout << "\n";
        num += 1;
    }
    for(int k = n-1; k >= 1; --k){
        ll i = 1;
        ll j = k;
        while(i <= n && j >= 1){
            pCP[num][i] = pCP[num][i-1] + a[i][j];
//            cout << pCP[num][i] << " ";
            soCP[i][j] = num;
            i += 1;
            j -= 1;
        }
//        cout << "\n";
        num += 1;
    }
//    cout << "\n";
}

ll tinhGiaTri(ll i, ll j, ll len){
    ll dgCC, dgCP;
    ll x = i, y = j + len - 1;
    if(soCC[i][j] <= n){
        dgCC = pCC[soCC[i][j]][j+len-1] - pCC[soCC[i][j]][j-1];
    }
    else{
       dgCC = pCC[soCC[i][j]][i+len-1] - pCC[soCC[i][j]][i-1];
    }
    if(soCP[x][y] <= n){
        dgCP = pCP[soCP[x][y]][n-j+1] - pCP[soCP[x][y]][n-(j+len-1)];
    }
    else{
        dgCP = pCP[soCP[x][y]][i+len-1] - pCP[soCP[x][y]][i-1];
    }
    return dgCC - dgCP;
}

void test(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << soCC[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << soCP[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

ll matrix(){
    ll res = 0;
    for(int len = 2; len <= n; ++len){
        for(int i = 1; i <= n - len + 1; ++i){
            for(int j = 1; j <= n - len + 1; ++j){
                res = max(res, tinhGiaTri(i, j, len));
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MATRIX.INP", "r", stdin);
    freopen("MATRIX.OUT", "w", stdout);
    readData();
    prefixSum1();
    prefixSum2();
//    test();
    ll res;
    res = matrix();
    cout << res;
    return 0;
}
