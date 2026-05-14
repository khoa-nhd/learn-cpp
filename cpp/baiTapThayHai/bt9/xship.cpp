#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, q;
ll a[maxN];
ll pre[maxN], suf[maxN];
ll change = 0;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a, a + n, greater<ll>());
    pre[0] = a[0];
    for(int i = 1; i < n; ++i){
        pre[i] = pre[i-1] + a[i];
    }
    suf[n-1] = a[n-1];
    for(int i = n-2; i >= 0; --i){
        suf[i] = suf[i+1] + a[i];
    }
}

ll xship(){
    ll d = 0, c = n-1;
    ll duong = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(a[half] + change >= 0){
            d = half + 1;
            duong = half;
        } else{
            c = half - 1;
        }
    }
    ll res = 0;
    if(duong != -1){
        res += pre[duong] + change * (duong + 1);
    }
    if(duong != n - 1){
        res += abs(suf[duong+1] + change * (n - (duong+1)));
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("XSHIP.INP", "r", stdin);
    freopen("XSHIP.OUT", "w", stdout);
    readData();
    cin >> q;
    for(int i = 0; i < q; ++i){
        ll c;
        cin >> c;
        change += c;
        ll res;
        res = xship();
        cout << res << "\n";
    }
    return 0;
}
