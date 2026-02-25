#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cntA[26] = {};
string a, b;

ll getpass(){
    ll res = (ll)a.size() * (ll)b.size();
    for(int i = 1; i < a.size(); ++i){
        cntA[a[i] - 'a'] += 1;
    }
    for(int i = 0; i < b.size() - 1; ++i){
        res -= cntA[b[i] - 'a'];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GETPASS.INP", "r", stdin);
    freopen("GETPASS.OUT", "w", stdout);
    cin >> a >> b;
    ll res;
    res = getpass();
    cout << res;
    return 0;
}
