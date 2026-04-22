#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll sumxor(){
    ll cnt[30] = {};
    for(int i = 0; i < 30; ++i){
        for(int j = 0; j < n; ++j){
            cnt[i] += ((a[j] >> i) & 1);
        }
    }
//    for(int i = 0; i < 5; ++i) cout << cnt[i] << " ";
//    cout << "\n";
    ll res = 0;
    for(int i = 0; i < 30; ++i){
        for(int j = 0; j < n; ++j){
            if(((a[j] >> i) & 1) == 0) res += cnt[i] * (1 << i);
            else res += (n - cnt[i]) * (1 << i);
        }
    }
    return res / 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUMXOR.INP", "r", stdin);
    freopen("SUMXOR.OUT", "w", stdout);
    readData();
    ll res;
    res = sumxor();
    cout << res;
    return 0;
}
