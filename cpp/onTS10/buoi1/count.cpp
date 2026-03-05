#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, a[maxN];
ll prefix[maxN];
ll cnt[maxN] = {};
ll sum = 0;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
}

ll sol(){
    if(sum % 3 != 0) return 0;
    ll res = 0;
    prefix[0] = a[0];
    for(int i = 1; i < n; ++i){
        prefix[i] = prefix[i-1] + a[i];
    }
    for(int i = 0; i < n-1; ++i){
        if(prefix[i] == sum / 3 * 2) cnt[i] = 1;
        cout << cnt[i] << " ";
    }
    cout << "\n";
    for(int i = n-2; i >= 0; --i){
        cnt[i] += cnt[i+1];
        cout << cnt[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < n - 1; ++i){
        if(prefix[i] == sum / 3){
            res += cnt[i+1];
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();
    ll res = 0;
    res = sol();
    cout << res;
    return 0;
}
