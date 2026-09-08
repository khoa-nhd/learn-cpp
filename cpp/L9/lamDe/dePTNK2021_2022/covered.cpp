#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x1, y11, x2, y2, x3, y3, x4, y4;

ll sol(){
    ll res;
    if((x3 <= x2 && x3 >= x1) || (x4 <= x2 && x4 >= x1)){
        res = min(abs(y2 - y3), abs(y4 - y11));
        return res * res;
    } else if((y3 >= y11 && y3 <= y2) || (y4 >= y11 && y4 <= y2)){
        res = min(abs(x2 - x3), abs(x4 - x1));
        return res * res;
    } else if(x2 < x3 && y2 < y3){
        ll a = x3 - x2;
        ll b = y3 - y2;
        return a*a + b*b;
    } else if(x2 < x3 && y4 < y11){
        ll a = x3 - x2;
        ll b = y11 - y4;
        return a*a + b*b;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> x1 >> y11 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    ll res = sol();
    if(res == -1){
        swap(x1, x3);
        swap(y11, y3);
        swap(x2, x4);
        swap(y2, y4);
        res = sol();
    }
    cout << res;
    return 0;
}
