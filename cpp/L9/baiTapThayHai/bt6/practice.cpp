#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void test(){
    for(int i = 1; i < 100; ++i){
        ll sum = 0;
        for(int j = 1; j <= i; ++j){
            cout << i / j << " ";
            sum += i/j;
        }
        cout << "     " << sum;
        cout << "\n";
    }
}

ll practice(){
    ll res = 0;
    ll ngay = 1;
    while(ngay <= n){
        ll buoc = n / ngay;
        ll ngayCuoi = n / buoc;
        res += buoc * (ngayCuoi - ngay + 1);
        ngay = ngayCuoi + 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PRACTICE.INP", "r", stdin);
    freopen("PRACTICE.OUT", "w", stdout);
//    test();
    cin >> n;
    ll res;
    res = practice();
    cout << res;
    return 0;
}
