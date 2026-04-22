#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[maxN], k;
ll chuyen[maxN];

void readData(){
    cin >> k >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

//ll pgcd(){ ucln là k
//    ll res = 0;
//    for(int i = 0; i < n; ++i){
//        if(a[i] % k > k - (a[i] % k)) chuyen[i] = a[i] + k-(a[i] % k);
//        else chuyen[i] = a[i] - (a[i] % k);
//    }
//    ll ucln = chuyen[0];
//    for(int i = 1; i < n; ++i){
//        ucln = __gcd(ucln, chuyen[i]);
//    }
//    ll minn = LLONG_MAX, minIdx = -1;
//    if(ucln > k){
//        for(int i = 0; i < n; ++i){
//            ll mot = abs(a[i] - (chuyen[i] - k));
//            ll hai = abs(a[i] - (chuyen[i] + k));
//            ll minTemp = min(mot, hai);
//            if(minn > minTemp){
//                minn = minTemp;
//                minIdx = i;
//            }
//        }
//    }
//    for(int i = 0; i < n; ++i){
//        if(i == minIdx) continue;
//        res += abs(a[i] - chuyen[i]);
//    }
//    if(minIdx != -1) res += minn;
//    return res;
//}

ll pgcd(){ // ucln là k hoặc bội của k
    ll res = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] % k > k - (a[i] % k)) chuyen[i] = a[i] + k-(a[i] % k);
        else chuyen[i] = a[i] - (a[i] % k);
        if(chuyen[i] <= 0) chuyen[i] = a[i] + k-(a[i] % k);
    }
    for(int i = 0; i < n; ++i){
        res += abs(a[i] - chuyen[i]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PGCD.INP", "r", stdin);
    freopen("PGCD.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        ll res;
        res = pgcd();
        cout << res << "\n";
    }
    return 0;
}
