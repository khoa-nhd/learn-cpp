#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll soMod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> s;
    ll res = 1;
    ll curr = 1;
    for(int i = 1; i < s.size(); ++i){
        if(s[i] != s[i-1]){
            res *= curr;
            res %= soMod;
            curr = 1;
        } else{
            curr += 1;
        }
    }
    res *= curr;
    res %= soMod;
    cout << res;
    return 0;
}
