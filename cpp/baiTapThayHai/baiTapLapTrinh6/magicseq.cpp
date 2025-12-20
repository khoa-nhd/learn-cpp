#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll tongchuso(ll n){
    ll res = 0;
    while(n > 0){
        res += n%10;
        n /= 10;
    }
    return res;
}

void test(){
    for(int i = 1; i < 300; ++i){
        ll temp = i;
        while(temp >= 10){
            temp = tongchuso(temp);
        }
        cout << temp << "\n";
    }
}

ull magicseq(ll n){
    ull res = 0;
    ull tron = n / 9;
    res += tron * 45;
    for(int i = 1; i <= n % 9; ++i){
        res += i;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MAGICSEQ.INP", "r", stdin);
    freopen("MAGICSEQ.OUT", "w", stdout);
//    test();
    ll q;
    cin >> q;
    for(int i = 0; i < q; ++i){
        ll l, r;
        cin >> l >> r;
        ll res = magicseq(r) - magicseq(l-1);
        cout << res << "\n";
    }
    return 0;
}
