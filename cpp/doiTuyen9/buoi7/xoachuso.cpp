#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll k;
int a[300] = {};

void xoachuso(){
    vector<ll> res;
    ll n = s.size() - k;
    for(int i = 0; i < s.size(); ++i){
        a[i] = s[i] - '0';
    }
    for(int i = 0; i < s.size(); ++i){
        ll maxVal = LLONG_MIN;
        for(int j = i; j < s.size(); ++j){
            if(s.size() - j >= n - res.size()){
                maxVal = max(maxVal, (ll)a[j]);
            }
        }
        if(maxVal == a[i]){
            res.push_back(a[i]);
            k -= 1;
        }
        if(res.size() == n) break;
    }
    for(ll x : res) cout << x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("XOACHUSO.INP", "r", stdin);
    freopen("XOACHUSO.OUT", "w", stdout);
    cin >> s >> k;
    xoachuso();
    return 0;
}
