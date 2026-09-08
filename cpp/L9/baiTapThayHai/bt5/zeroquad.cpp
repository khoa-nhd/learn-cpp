#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 2005
#define maxN2 4000005

//unordered_map<ll, ll> cnt;
ll cnt[maxN2] = {};
ll cong = 2000000;
ll n, a[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll zeroQuad(){
    // a = -b
    // a[i] + a[j] = -(a[k] + a[t]
    // j < i < k < t
    ll res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            cnt[-(a[i] + a[j]) + cong] += 1; // tính các cặp k, t
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j) cnt[-(a[i] + a[j]) + cong] -= 1; // loại các cặp có a[i]
        for(int j = 0; j < i; ++j){ // tính cặp i, j
            res += cnt[a[i] + a[j] + cong];
//            cout <<  cnt[a[i] - a[j]] << "\n";
        }
    }
    return res;
}

int main(){
    freopen("ZEROQUAD.INP", "r", stdin);
    freopen("ZEROQUAD.OUT", "w", stdout);
    readData();
    ll res;
    res = zeroQuad();
    cout << res;
    return 0;
}
