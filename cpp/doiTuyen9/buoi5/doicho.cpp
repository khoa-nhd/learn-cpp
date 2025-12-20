#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll m, n, k, l, a[maxN][maxN];

void readData(){
    cin >> m >> n >> k >> l;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
    k -= 1;
    l -= 1;
}

void doicho(){
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(i == k) cout << a[l][j];
            else if(i == l) cout << a[k][j];
            else cout << a[i][j];
            cout << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    doicho();
    return 0;
}
