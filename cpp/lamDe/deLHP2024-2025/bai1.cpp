#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, k, a[maxN];
//ll luot[maxN] = {};
unordered_map<ll, ll> luotdi;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

//ll tuyetchieu(){
//    ll minViPham = LLONG_MAX;
//    for(int i = 0; i < maxN; ++i){
//        luot[i] = -1;
//    }
//    for(int i = 0; i < n; ++i){
//        if(luot[a[i]] != -1){
////            cout << i << " " << luot[a[i]] << " ";
////            cout << i - luot[a[i]] << "\n";
//            if(i - luot[a[i]] < k){
//                minViPham = min(minViPham, a[i]);
//            }
//        }
//        luot[a[i]] = i;
//    }
//    if(minViPham == LLONG_MAX) return -1;
//    return minViPham;
//}

ll tuyetchieu(){
    ll minViPham = LLONG_MAX;
    for(int i = 0; i < n; ++i){
        if(luotdi.find(a[i]) != luotdi.end()){
//            cout << i << " " << luot[a[i]] << " ";
//            cout << i - luot[a[i]] << "\n";
            if(i - luotdi[a[i]] < k){
                minViPham = min(minViPham, a[i]);
            }
        }
        luotdi[a[i]] = i;
    }
    if(minViPham == LLONG_MAX) return -1;
    return minViPham;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    ll result;
    result = tuyetchieu();
    cout << result;
    return 0;
}
