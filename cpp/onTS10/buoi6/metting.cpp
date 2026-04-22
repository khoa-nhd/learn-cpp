#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll n;
    char c;
    cin >> n >> c;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        bool co = true;
        for(char x : s){
            if(x == c){
                co = false;
                break;
            }
        }
        if(co) cout << s << "\n";
    }
    return 0;
}
