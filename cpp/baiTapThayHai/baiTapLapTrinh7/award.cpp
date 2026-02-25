#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[1005];
ll maxNhan[1005] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll award(){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        maxNhan[i] = a[i];
        for(int j = 0; j < i; ++j){
            if(a[i] > a[j]) maxNhan[i] = max(maxNhan[i], maxNhan[j] + a[i]);
        }
    }
    for(int i = 0; i < n; ++i){
        res = max(res, maxNhan[i]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("AWARD.INP", "r", stdin);
    freopen("AWARD.OUT", "w", stdout);
    readData();
    ll res;
    res = award();
    cout << res;
    return 0;
}
