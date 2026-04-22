#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, k;
vector<ll> so;

ll mu10(ll x){
    ll res = 1;
    for(int i = 0; i < x; ++i){
        res *= 10;
    }
    return res;
}

ll sochuso(ll x){
    ll res = 0;
    while(x > 0){
        x /= 10;
        res += 1;
    }
    return res;
}

ll mer(ll x, ll y){
    ll res = x;
    while(y > 0){
        x *= 10;
        x += y % 10;
        y /= 10;
    }
    return x;
}

void makePalind(ll x){
    ll num = sochuso(x);
    if(num + num == n){
        ll temp = mer(x, x);
        if(temp % m == 0) so.push_back(temp);
    } else{
        for(int i = 0; i < 10; ++i){
            ll a = x * 10 + i;
            ll temp = mer(a, x);
            if(temp % m == 0) so.push_back(temp);
        }
    }
}

void palind(){
    ll minv = mu10(n/2-1);
    ll maxv = mu10(n/2);
    for(int i = minv; i < maxv; ++i){
        makePalind(i);
    }
    sort(so.begin(), so.end());
    cout << so.size() << "\n" << so[k-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PALIND.INP", "r", stdin);
    freopen("PALIND.OUT", "w", stdout);
    cin >> n >> m >> k;
    palind();
    return 0;
}
