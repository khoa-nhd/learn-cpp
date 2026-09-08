#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[100005] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

bool checkPossible(ll idx){
    ll diemCong = 1;
    ll maxDiemNgKhac = LLONG_MIN;
    for(int i = n-1; i > idx; --i){
        maxDiemNgKhac = max(maxDiemNgKhac, a[i] + diemCong);
        diemCong += 1;
    }
//    for(int i = 0; i < idx; ++i){
//        maxDiemNgKhac = max(maxDiemNgKhac, a[i] + diemCong);
//        diemCong += 1;
//    }
    return maxDiemNgKhac <= a[idx] + n;
}

ll bonus(){
    sort(a, a + n);
    ll d = 0;
    ll c = n-1;
    ll minPossibleIdx = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        bool possible = checkPossible(half);
        if(possible){
            c = half - 1;
            minPossibleIdx = half;
        } else{
            d = half + 1;
        }
    }
    return n - minPossibleIdx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    ll res;
    res = bonus();
    cout << res;
    return 0;
}
