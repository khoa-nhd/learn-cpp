#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll n;

ll chocolate(){
    ll res = 1;
    ll idx = 0;
    while(s[idx] != 'X' && idx < n){
        idx += 1;
    }
    if(idx == n) return 0;
    while(idx < n){
        ll prev = 1;
        while(s[idx] != 'X' && idx < n){
            idx += 1;
            prev += 1;
        }
        if(idx < n) res *= prev;
        idx += 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CHOCOLATE.INP", "r", stdin);
    freopen("CHOCOLATE.OUT", "w", stdout);
    cin >> s;
    n = s.size();
    ll res;
    res = chocolate();
    cout << res;
    return 0;
}
