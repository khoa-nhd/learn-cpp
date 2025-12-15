#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define maxN 8005
#define maxN2 65000000
#define maxN3 2000000

ll n, a[maxN];
ll sum[maxN2];
unordered_map<ll, ll> m;
ll cnt[maxN3] = {};
ll k;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cin >> k;
}
//void readData(){
//    cin >> n;
//    cin >> k;
//    for(int i = 0; i < n; ++i){
//        cin >> a[i];
//    }
//}

void sol(){
    ll prefixSum[maxN] = {};
    prefixSum[0] = 0;
    for(int i = 1; i <= n; ++i){
        prefixSum[i] = prefixSum[i-1] + a[i-1];
//        cout << prefixSum[i] << " ";
    }
//    cout << "\n";

    ll res = 0;
    ll dem = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            sum[dem] = prefixSum[j] - prefixSum[i-1];
//            cout << sum[dem] << " ";
            dem += 1;
        }
    }
//    cout << "\n";

//    for(int i = 0; i < dem; ++i){
//        if(sum[i] == 0) continue;
//        m[sum[i]] += 1;
//        ll need = k / sum[i];
//        if(sum[i] * need == k){
//            if(m.find(need) != m.end()){
//                res += m[need];
//            }
//        }
//    }
    for(int i = 0; i < dem; ++i){
        if(sum[i] == 0) continue;
        cnt[sum[i]] += 1;
        ll need = k / sum[i];
        if(sum[i] * need == k){
            res += cnt[need];
        }
    }
    cout << res*2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUMK.INP", "r", stdin);
    freopen("SUMK.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
