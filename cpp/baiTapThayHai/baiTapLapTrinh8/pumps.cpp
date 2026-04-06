#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll b, d;

void test(){
    ll cnt = 0;
    for(int c = 1; c < b; ++c){
        if((b*b - c*b) % d == 0){
            cout << c << " " << (b*b - c*b) / d << "\n";
            cnt += 1;
        }
    }
//    for(int a = 1; a * d < b * b; ++a){
//        if((a * d) % b == 0){
//            cout << a << " " << b - (a*d)/b << "\n";
//            cnt += 1;
//        }
//    }
    cout << cnt << "\n";
    cout << "\n";
}

ll pump(){
    ll g = __gcd(b, d);
    d = d / g;
    ll res = (b - 1) / d;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PUMPS.INP", "r", stdin);
    freopen("PUMPS.OUT", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> b >> d;
//        test();
        ll res;
        res = pump();
        cout << res << "\n";
    }
    return 0;
}
