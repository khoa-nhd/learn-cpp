#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll a[maxN], n;
ll cnt[10] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        cnt[a[i]] += 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SEAT.INP", "r", stdin);
    freopen("SEAT.OUT", "w", stdout);
    readData();
    ll res = cnt[4];
    res += (cnt[2] + 1) / 2;
    res += cnt[3];
    cnt[1] -= cnt[3];
    cnt[1] -= cnt[2] % 2 * 2;
    res += max(0LL, (cnt[1] + 3) / 4);
    cout << res;
    return 0;
}
