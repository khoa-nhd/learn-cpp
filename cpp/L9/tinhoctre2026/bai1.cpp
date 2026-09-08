#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

ll bai1(){
    ll prev = 0;
    ll res = 0;
    for(int i = 1; i < s.size(); ++i){
        if(s[prev] != s[i]){
            prev = i;
        } else{
            res += 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> s;
    ll res;
    res = bai1();
    cout << res;
    return 0;
}
