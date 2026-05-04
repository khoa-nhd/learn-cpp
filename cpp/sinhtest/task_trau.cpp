#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("i.inp", "r", stdin);
    freopen("o.ans", "w", stdout);
    ll a, b;
    cin >> a >> b;
    ll c = 0;
    while(true){
        if((a + c) % b == 0 && (b + c) % a == 0){
            break;
        }
        if((a - c) % b == 0 && (b - c) % a == 0){
            c = -c;
            break;
        }
        ++c;
    }
    cout << c;
    return 0;
}
