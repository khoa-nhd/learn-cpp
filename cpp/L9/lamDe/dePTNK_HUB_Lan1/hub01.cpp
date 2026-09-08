#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, d, a[maxN];

void readData(){
    cin >> n >> d;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll sol(){
    ll res = 0;
    for(int i = 1; i < n; ++i){
        if(abs(a[i] - a[i-1]) > d){
            res += 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("HUB01.INP", "r", stdin);
//    freopen("HUB01.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
