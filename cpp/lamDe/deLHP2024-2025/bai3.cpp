#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, m, a[maxN], r[maxN];
ll result[maxN] = {};

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i){
       cin >> r[i];
    }
}

void locnuoc(){
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(r[i] >= a[j]){
                result[i] += a[j];
                a[j] = 0;
            } else{
                result[i] += r[i];
                a[j] -= r[i];
            }
        }
    }
    for(int i = 0; i < maxN; ++i){
        if(result[i] != 0){
            cout << result[i] << " ";
        } else{
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    locnuoc();
    return 0;
}
