#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string str;

ll anacount(){
    ll n = str.size() - 1;
    ll res = 0;
    unordered_map<string, ll> um;
    for(int len = 1; len <= n; ++len){
        for(int s = 0; s + len - 1 <= n; ++s){
            string temp = str.substr(s, len);
            sort(temp.begin(), temp.end());
            res += um[temp];
            um[temp] += 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ANACOUNT.INP", "r", stdin);
    freopen("ANACOUNT.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> str;
        ll res;
        res = anacount();
        cout << res << "\n";
    }
    return 0;
}
