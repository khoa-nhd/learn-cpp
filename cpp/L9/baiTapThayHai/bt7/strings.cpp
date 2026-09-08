#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a, b;

ll strings(){
    ll res = 0;
    ll n = b.size();
    for(int i = 0; i <= a.size() - n; ++i){
        string d = a.substr(i, n);
        for(int k = 0; k < n; ++k){
            string c;
            for(int j = k; j < n; ++j){
                c.push_back(b[j]);
            }
            for(int j = 0; j < k; ++j){
                c.push_back(b[j]);
            }
            if(c == d){
                res += 1;
                break;
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("STRINGS.INP", "r", stdin);
    freopen("STRINGS.OUT", "w", stdout);
    cin >> a >> b;
    ll res;
    res = strings();
    cout << res;
    return 0;
}
