#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[maxN];
ll ten[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll minarrows(){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        if(ten[a[i]] > 0){
            ten[a[i]] -= 1;
        } else{
            res += 1;
        }
        if(a[i] - 1 > 0) ten[a[i] - 1] += 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MINARROWS.INP", "r", stdin);
    freopen("MINARROWS.OUT", "w", stdout);
    readData();
    ll res;
    res = minarrows();
    cout << res;
    return 0;
}
