#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[maxN];
ll cnt[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll pydisks(){
    for(int i = 0; i < n; ++i){
        if(cnt[a[i]+1] > 0) cnt[a[i]+1] -= 1;
        cnt[a[i]] += 1;
    }
    ll res = 0;
    for(int i = 0; i < maxN; ++i){
        res += cnt[i];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PYDISKS.INP", "r", stdin);
    freopen("PYDISKS.OUT", "w", stdout);
    readData();
    ll res;
    res = pydisks();
    cout << res;
    return 0;
}
