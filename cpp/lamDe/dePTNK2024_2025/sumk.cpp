#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define maxN 8005
#define maxN2 65000000
#define maxN3 2000000

ll n, a[maxN];
//ll sum[maxN2];
unordered_map<ll, ll> m;
ll cnt[maxN3] = {};
bool marked[maxN3] = {};
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
    ll res = 0;
    for(int i = 1; i <= n; ++i){
        prefixSum[i] = prefixSum[i-1] + a[i-1];
    }

    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            cnt[prefixSum[j] - prefixSum[i-1]] += 1;
//            cout << prefixSum[j] - prefixSum[i-1] << " ";
        }
    }
//    cout << "\n";

    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; ++j){
            ll temp = prefixSum[j] - prefixSum[i-1];
            if(temp == 0) continue;
            ll need = k / temp;
            if(temp * need == k && !marked[temp]){
                res += cnt[need]*cnt[temp];
            }
            marked[temp] = true;
        }
    }
    cout << res;
//
//    for(int i = 1; i <= n; ++i){
//        for(int j = i; j <= n; ++j){
//            ll temp = prefixSum[j] - prefixSum[i-1];
//            if(temp == 0) continue;
//            ll need = k / temp;
//            if(temp * need == k){
//                res += cnt[need];
//            }             cnt[temp] += 1;
//        }
//    }
//
//    cout << res*2;
//
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
