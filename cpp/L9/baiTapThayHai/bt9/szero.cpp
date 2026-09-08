#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN];
ll pre[maxN];

void readData(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

void szero(){
    ll res = LLONG_MIN;
    ll l = 0, h = 0;
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i-1] + a[i];
        if(pre[i] == 0){
            res = i;
            l = 1;
            h = i;
        }
    }
    unordered_map<ll, ll> um;
    for(int i = 1; i <= n; ++i){
        if(um[pre[i]] != 0){
            if(res < i - um[pre[i]]){
                res = i - um[pre[i]];
                l = um[pre[i]] + 1;
                h = i;
            }
        } else um[pre[i]] = i;
    }
    cout << l << " " << h;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SZERO.INP", "r", stdin);
    freopen("SZERO.OUT", "w", stdout);
    readData();
    szero();
    return 0;
}
