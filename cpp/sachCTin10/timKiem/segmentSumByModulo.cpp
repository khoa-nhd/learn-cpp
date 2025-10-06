#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100000

ll n, a[maxN] = {}, d;

void readData(){
    cin >> n >> d;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll solve(){
    ll prefixMod[maxN] = {};
    prefixMod[0] = a[0] % d;
    for(int i = 1; i < n; ++i){
        prefixMod[i] = (prefixMod[i-1] + a[i]) % d;
        if(a[i] % d == 0){
            return 1;
        }
    }

    vector<ll> remain(d, -1);
    int minn = INT_MAX;
    for(int i = 0; i < n; ++i){
        if(prefixMod[i] == 0){
            minn = min(i+1, minn);
        }
        if(remain[prefixMod[i]] == -1){
            remain[prefixMod[i]] = i;
        } else{
            int khoangCach = abs(remain[prefixMod[i]] - i);
            minn = min(khoangCach, minn);
            remain[prefixMod[i]] = i;
        }
    }
    if(minn == INT_MAX){
        return -1;
    }
    return minn;
}

int main(){
    freopen("i.inp", "r", stdin);
    freopen("o.out", "w", stdout);
    readData();
    ll result;
    result = solve();
    cout << result;
    return 0;
}
