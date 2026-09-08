#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n;
ll a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void modulo(){
    for(int i = 1; i < n; ++i) a[i] = abs(a[i] - a[0]);
    ll g = 0;
    for(int i = 1; i < n; ++i) g = __gcd(a[i], g);
    vector<ll> res;
    for(int i = 1; i * i <= g; ++i){
        if(i * i == g) res.push_back(i);
        else if(g % i == 0){
            res.push_back(i);
            res.push_back(g/i);
        }
    }
    sort(res.begin(), res.end());
    for(ll x : res) if(x != 1) cout << x << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MODULO.INP", "r", stdin);
    freopen("MODULO.OUT", "w", stdout);
    readData();
    modulo();
    return 0;
}
