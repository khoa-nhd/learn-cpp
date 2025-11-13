#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 25

ll n;

struct cost{
    ll mot, hai, ba;
} a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].mot >> a[i].hai >> a[i].ba;
    }
}

//ll paint(ll idx, ll prev, ll prevCost){ đúng nhưng không hiệu quả
//    ll one = LLONG_MAX;
//    ll two = LLONG_MAX;
//    ll three = LLONG_MAX;
//    ll res = 0;
//    if(idx == n - 1){
//        if(prev == 0){
//            one = a[idx].mot + prevCost;
//            two = a[idx].hai + prevCost;
//            three = a[idx].ba  + prevCost;
//        } else if(prev == 1){
//            two = a[idx].hai + prevCost;
//            three = a[idx].ba + prevCost;
//        } else if(prev == 2){
//            one = a[idx].mot + prevCost;
//            three = a[idx].ba + prevCost;
//        } else{
//            two = a[idx].hai + prevCost;
//            one = a[idx].mot + prevCost;
//        }
//        res = min(one, min(two, three));
//        return res;
//    }
//    if(prev == 0){
//        one = paint(idx + 1, 1, prevCost + a[idx].mot);
//        two = paint(idx + 1, 2, prevCost + a[idx].hai);
//        three = paint(idx + 1, 3, prevCost + a[idx].ba);
//    } else if(prev == 1){
//        two = paint(idx + 1, 2, prevCost + a[idx].hai);
//        three = paint(idx + 1, 3, prevCost + a[idx].ba);
//    } else if(prev == 2){
//        one = paint(idx + 1, 1, prevCost + a[idx].mot);
//        three = paint(idx + 1, 3, prevCost + a[idx].ba);
//    } else{
//        two = paint(idx + 1, 2, prevCost + a[idx].hai);
//        one = paint(idx + 1, 1, prevCost + a[idx].mot);
//    }
//    res = min(one, min(two, three));
//    return res;
//}

ll dp[5][25] = {};

ll paint(){
    dp[1][0] = a[0].mot;
    dp[2][0] = a[0].hai;
    dp[3][0] = a[0].ba;
    for(int i = 1; i < n; ++i){
        dp[1][i] = min(dp[2][i-1], dp[3][i-1]) + a[i].mot;
        dp[2][i] = min(dp[1][i-1], dp[3][i-1]) + a[i].hai;
        dp[3][i] = min(dp[1][i-1], dp[2][i-1]) + a[i].ba;
    }
    return min(dp[1][n-1], min(dp[2][n-1], dp[3][n-1]));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PAINT.INP", "r", stdin);
    freopen("PAINT.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        ll res;
        res = paint();
        cout << res << "\n";
    }
    return 0;
}
