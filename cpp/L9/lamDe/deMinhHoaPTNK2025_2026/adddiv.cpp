#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b;

int main(){
    cin >> a >> b;
    ll bcnn = (a * b) / __gcd(a, b);
    if(a == b){
        cout << 0;
    } else if(bcnn == a || bcnn == b){
        cout << bcnn - a - b + bcnn;
    } else cout << bcnn - a - b;
    return 0;
}

//ll cach1(){ ko hiệu quả
//    ll c = 0;
//    while(!((a + c) % b == 0 && (b + c) % a == 0)){
//        c += 1;
//    }
//    return c;
//}
//
//ll cach2(){ ko hiệu quả
//    if(a > b) swap(a, b);
//    ll c1 = b - a;
//    ll c2 =  a - (b % a);
//    if(c2 == a) c2 = 0;
//    ll i = 0, j = 0;
//    while(true){
//        j = (((b * i) + c1) - c2) / a;
//        if(c1 + b * i == c2 + a * j) return c1 + b * i;
//        i += 1;
//    }
//    return c1 + b * i;
//}
//
//int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie();
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
//    cin >> a >> b;
//    for(int i = 1; i <= 10; ++i){
//        for(int j = 1; j <= 10; ++j){
//            a = i;
//            b = j;
//            cout << a << " " << b << ": " << cach1() << " " << cach2() << "\n";
//        }
//    }
//    ll res;
//    res = cach2();
//    cout << res;
//    return 0;
//}
