#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[1005][1005];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
}

void multitable(){
    for(int i = 0; i < n; ++i){
        cout << sqrt(a[i][i]) << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    multitable();
    return 0;
}
