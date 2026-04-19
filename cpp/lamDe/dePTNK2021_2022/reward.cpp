#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 2000005

ll n, y, x;
string s;
ll ci[] = {-1, 0, 1, 0};
ll cj[] = {0, 1, 0, -1};
ll gtDau[maxN];
unordered_map<ll, ll> um;

void readData(){
    cin >> n >> x >> y;
    cin >> s;
}

void calGTDau(){
    gtDau[1] = 1;
    for(int i = 1; i < n; ++i){
        gtDau[i+1] = gtDau[i] + i;
    }
    ll j = n;
    for(int i = n + 1; i < 2*n; ++i){
        gtDau[i] = gtDau[i-1] + j;
        j -= 1;
    }
//    for(int i = 1; i < 2*n; ++i){
//        cout << gtDau[i] << " ";
//    }
}

int change(char x){
    if(x == 'N') return 0;
    if(x == 'E') return 1;
    if(x == 'S') return 2;
    return 3;
}

ll cal(ll i, ll j){
    ll num = i + j - 1;
    if(num % 2 == 0){
        if(num <= n) return gtDau[num] + (i - 1);
        return gtDau[num] + (n - j);
    } else{
        if(num <= n) return gtDau[num] + (j - 1);
        return gtDau[num] + (n - i);
    }
    return 0;
}

ll sol(){
    ll res = cal(x, y);
    um[res] = 1;
    for(int i = 0; i < s.size(); ++i){
        ll m = change(s[i]);
        x += ci[m];
        y += cj[m];
        ll v = cal(x, y);
        if(um[v] == 0){
            res += v;
            um[v] += 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    calGTDau();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
