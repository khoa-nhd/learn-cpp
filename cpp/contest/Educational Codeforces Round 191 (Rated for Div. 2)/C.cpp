#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll n, k;

void sol(){
    vector<ll> res(n+1, 0);
    ll totaldong = 0;
    ll balance = 0;
    ll minbalance = 0, minidx = 0;
    for(int i = 0; i < n; ++i) totaldong += (s[i] == ')');
    for(int i = 0; i < n; ++i){
        balance += (s[i] == '(') ? 1 : -1;
        if(minbalance > balance){
            minbalance = balance;
            minidx = i+1;
        }
    }
    for(int i = 0; i < minidx && k > 0; ++i){
        if(s[i] == '('){
            k -= 1;
            res[i] = 1;
        }
    }
    for(int i = minidx; i < n && k > 0; ++i){
        if(s[i] == ')'){
            k -= 1;
            res[i] = 1;
        }
    }
    for(int i = 0; i < n; ++i) cout << res[i];
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n >> k;
        cin >> s;
        sol();
    }
    return 0;
}
