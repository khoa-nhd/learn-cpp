#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define maxN 100005

ll n;
ll b[maxN] = {};
vector<ll> c;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    for(int i = 0; i < n; ++i){
        ll temp;
        cin >> temp;
        c.push_back(temp);
    }
}

ull safeAbs(ll x){
    if(x >= 0) return (ull)x;
    return (ull)abs(x+1) + 1;
}

ull congAbs(ll x, ll y){
    if(x == 0 || y == 0) return safeAbs(x + y);
    if((x > 0 && y < 0) || (x < 0 && y > 0)) return safeAbs(x + y);
    ull x2 = x, y2 = y;
    if(x < 0) x2 = safeAbs(x+1)+1;
    if(y < 0) y2 = safeAbs(y+1)+1;
    return x2 + y2;
}

ull game(){
    sort(c.begin(), c.end());
    ull res = ULLONG_MAX;
    for(int i = 0; i < n; ++i){
        ll need = -b[i];
        auto it = lower_bound(c.begin(), c.end(), need);
        if(it != c.end()) res = min(res, congAbs(b[i], *it));
        if(it != c.begin()) res = min(res, congAbs(b[i], *(it-1)));
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GAME.INP", "r", stdin);
    freopen("GAME.OUT", "w", stdout);
    readData();
    ull res;
    res = game();
    cout << res;
    return 0;
}

