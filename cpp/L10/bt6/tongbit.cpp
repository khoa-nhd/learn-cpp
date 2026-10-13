#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

ll cntbit1(ll x){
    int cnt = 0;
    while(x > 0){
        x &= x - 1;
        cnt += 1;
    }
    return cnt;
}

void sol(){
    ll x = n;
    ll res = 0;
    ll i = 2;
    n += 1;
    while(x > 0){
        x /= 2;
        res += n / i * i / 2 + max(0LL, n % i - i / 2);
        i *= 2;
    }
    cout << res << "\n";
}

void test(){
    ll cnt = 0;
    for(int i = 1; i <= 1000; ++i){
        cnt += cntbit1(i);
        n = i;
        cout << cnt << " ";
        sol();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TONGBIT.INP", "r", stdin);
    freopen("TONGBIT.OUT", "w", stdout);
    cin >> n;
//    test();
    sol();
    return 0;
}
