#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void sol(){
    ll curr = 0;
    ll res = 0;
    if(a[0] < 0){
        curr = a[0];
        res = a[0];
    }
    for(int i = 1; i < n; ++i){
        if(a[i] >= 0){
            curr = 0;
        } else{
            curr += a[i];
        }
        res = min(res, curr);
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        sol();
    }
    return 0;
}
