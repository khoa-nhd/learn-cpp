#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN];
ll pre[maxN], suf[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll gather(){
    sort(a, a + n);
    ll x;
    if(n % 2 == 1) x = a[n/2];
    else x = (a[n/2-1] + a[n/2])/2;
    ll res = 0;
    for(int i = 0; i < n; ++i) res += abs(x - a[i]);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GATHER.INP", "r", stdin);
    freopen("GATHER.OUT", "w", stdout);
    readData();
    ll res;
    res = gather();
    cout << res;
    return 0;
}
