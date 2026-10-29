#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, a[maxN], k;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
       cin >> a[i];
    }
}

//void sol(){
//    ll tong = 0;
//    ll res = 0;
//    for(int i = 0; i < n; ++i){
//        ll newtong = tong + a[i];
//        ll nho = (tong / k) * k + k;
//        ll lon = (newtong / k) * k;
//        if(nho <= lon){
//            res += 1;
//        }
//        tong = newtong;
//    }
//    cout << res;
//}

void sol(){
    ll tong = 0;
    ll res = 0;
    for(int i = 0; i < n; ++i){
        if(tong + a[i] >= k){
            res += 1;
        }
        tong = (tong + a[i]) % k;
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LAB.INP", "r", stdin);
    freopen("LAB.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
