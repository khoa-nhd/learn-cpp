#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        string a, b;
        cin >> a >> b;
        ll x = 10, y = 10;
        for(int i = 1; i <= 9; ++i){
            if(a.size() == 1 && a[0] - '0' == i) x = i;
            if(b.size() == 1 && b[0] - '0' == i) y = i;
        }
        if(a[0] == 'A') x = 11;
        if(b[0] == 'A') y = 11;
        ll s = x + y;
        while(s > 21){
            s -= 10;
        }
        if(s == 21) cout << "Blackjack\n";
        else if(s >= 10) cout << 21 << "\n";
        else cout << s + 11 << "\n";
    }
    return 0;
}
