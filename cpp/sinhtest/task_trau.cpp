#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, s, a[maxN];
ll pre[maxN] = {};

void readData(){
    cin >> n >> s;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

ll sol(){
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i-1] + a[i];
    }
    ll res = LLONG_MIN;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            if(pre[i] - pre[j-1] <= s){
                res = max(res, (ll)(i - j + 1));
            }
        }
    }
    if(res == LLONG_MIN) return -1;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.ANS", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
