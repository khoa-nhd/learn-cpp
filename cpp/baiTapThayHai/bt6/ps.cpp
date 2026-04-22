#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN];
ll prefixSum[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

void ps(){
//    cout << 0 << " ";
    for(int i = 1; i <= n; ++i){
        prefixSum[i] = prefixSum[i-1] + a[i];
//        cout << prefixSum[i] << " ";
    }
    vector<ll> bd;
    for(int i = 0; i <= n; ++i){
        if(bd.size() == 0 || prefixSum[bd.back()] > prefixSum[i]){
            bd.push_back(i);
        }
    }

    ll idx = bd.size() - 1;
    ll maxLen = LLONG_MIN;
    ll l, h;
    for(int i = n; i > 0; --i){
        if(idx == -1) break;
        while(prefixSum[i] > prefixSum[bd[idx]] && idx >= 0){
            ll len = i - bd[idx];
            if(maxLen < len){
                l = bd[idx] + 1;
                h = i;
                maxLen = len;
            }
            idx -= 1;
            if(idx == -1) break;
        }
    }
    cout << l << " " << h;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PS.INP", "r", stdin);
    freopen("PS.OUT", "w", stdout);
    readData();
    ps();
    return 0;
}
