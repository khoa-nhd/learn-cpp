#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

ll bracket(){
    ll res = 0;
    ll ngoacmo = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '(') ngoacmo += 1;
        if(s[i] == ')') ngoacmo -= 1;
        if(ngoacmo < 0){
            res += 1;
            ngoacmo += 2;
        }
    }
    res += ngoacmo/2;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BRACKET.INP", "r", stdin);
    freopen("BRACKET.OUT", "w", stdout);
    cin >> s;
    ll res;
    res = bracket();
    cout << res;
    return 0;
}
