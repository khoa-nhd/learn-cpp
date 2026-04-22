#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 105

ll n;

struct hcn{
    ll x1, y1, x2, y2;
} a[maxN];

ll dp[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }
}

bool cmp(hcn a, hcn b){
    if(a.x1 == b.x1) return a.y1 > b.y1;
    return a.x1 > b.x1;
}

bool checkInside(hcn a, hcn b){
    if(a.x1 <= b.x1 && a.y1 <= b.y1 && a.x2 >= b.x2 && a.y2 >= b.y2) return true;
    return false;
}

ll nested(){
    sort(a, a + n, cmp);
//    for(int i = 0; i < n; ++i) cout << a[i].x1 << " " << a[i].y1 << " " << a[i].x2 << " " << a[i].y2 << "\n";
    for(int i = 0; i < maxN; ++i) dp[i] = 1;
    ll maxPrev = 0;
    for(int i = 0; i < n; ++i){
        maxPrev = 0;
        for(int j = i - 1; j >= 0; --j){
            if(checkInside(a[i], a[j])){
                maxPrev = max(maxPrev, dp[j]);
            }
        }
//        ll temp = dp[i]+ maxPrev;
        dp[i] += maxPrev;
//        cout << dp[i] << " " << maxPrev << "\n";
    }

    ll res = -1;
    for(int i = 0; i < n; ++i){
//        cout << dp[i] << " ";
        res = max(res, dp[i]);
    }
//    cout << "\n";
    return res;
}

int main(){
    freopen("NESTED.INP", "r", stdin);
    freopen("NESTED.OUT", "w", stdout);
    readData();
    ll res = nested();
    cout << res;
    return 0;
}
