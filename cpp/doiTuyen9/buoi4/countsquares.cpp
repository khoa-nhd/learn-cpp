#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void countsquares(){
    ll canh = -1;
    ll n;
    cin >> n;
    ll a[1005] = {};
    for(int i = 0; i < n; ++i){
        ll temp;
        cin >> temp;
        a[temp] += 1;
    }
    for(int i = 1000; i > 0; --i){
        if(a[i] >= 4){
            canh = i;
            break;
        }
    }
    if(canh == -1){
        cout << -1 << "\n";
        return;
    } else{
        cout << canh*canh << " " << a[canh] / 4 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        countsquares();
    }
    return 0;
}
