#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll d, k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("KNUM.INP", "r", stdin);
    freopen("KNUM.OUT", "w", stdout);
    while(cin >> d >> k){
        vector<ll> res;
        res.push_back(d);
        ll nho = 0;
    //    cout << d << "\n";
        while(res.size() <= 1005){
            ll n = res.back() * k;
            n += nho;
            res.push_back(n % 10);
    //        cout << n % 10 << "\n";
            nho = n / 10;
            if(res.back() == d && nho == 0 && res[res.size()-2] != 0){
                res.pop_back();
                reverse(res.begin(), res.end());
                for(ll x : res) cout << x;
                cout << "\n";
                break;
            }
        }
        if(res.size() > 1005) cout << -1 << "\n";
    }
    return 0;
}
