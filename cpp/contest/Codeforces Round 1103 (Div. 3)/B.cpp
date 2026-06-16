#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll t, n, k;
    string s;
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n >> k;
        cin >> s;
        bool yes = true;
        for(int i = 0; i < n - k; ++i){
            if(s[i] == '1'){
                s[i] = '0';
                if(s[i+k] == '1') s[i+k] = '0';
                else s[i+k] = '1';
            }
        }
        for(int i = 0; i < n; ++i){
            if(s[i] == '1'){
                yes = false;
            }
        }
        if(yes) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}
