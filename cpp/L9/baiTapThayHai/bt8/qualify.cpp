#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005
#define maxN2 1005

int uoc[maxN] = {};
int a[maxN2] = {};
int n;

void sang(){
    for(int i = 1; i * i < maxN; ++i){
        uoc[i*i] += 1;
        for(int j = i + 1; j * i < maxN; ++j){
            uoc[i*j] += 2;
        }
    }
//    for(int i = 1; i <= 10; ++i){
//        cout << uoc[i] << "\n";
//    }
}

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll qualify(){
    int dp[maxN2] = {};
    for(int i = 0; i < maxN2; ++i) dp[i] = 1;
    for(int i = 0; i < n; ++i){
        for(int j = i - 1; j >= 0; --j){
            if(uoc[a[i]] == uoc[a[j]] && a[j] != a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; ++i){
//        cout << dp[i] << " ";
        res = max(res, dp[i]);
    }
//    cout << "\n";
//    cout << res << "\n";
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("QUALIFY.INP", "r", stdin);
    freopen("QUALIFY.OUT", "w", stdout);
    sang();
    ll r;
    cin >> r;
    ll res = -1;
    for(int i = 0; i < r; ++i){
        readData();
//        cout << n << "\n";
//        for(int i = 0; i < n; ++i){
//            cout << uoc[a[i]] << " ";
//        }
//        cout << "\n";
        res = max(res, qualify());
    }
    cout << res;
    return 0;
}
