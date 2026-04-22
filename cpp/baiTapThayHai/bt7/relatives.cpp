#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 2000005

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll relatives(){
    ll cnt[2000] = {};
    ll res = 0;
    for(int i = 0; i < n; ++i){
        bool co[10] = {};
        ll x = a[i];
        while(x > 0){
            co[x%10] = true;
            x /= 10;
        }
        ll v = 0;
        if(a[i] == 0) v = 1;
        else{
            for(int i = 0; i < 10; ++i){
                if(co[i]) v |= (1 << i);
            }
        }
        cnt[v] += 1;
    }
    for(int i = 0; i <= 1024; ++i){
        for(int j = i + 1; j <= 1024; ++j){
            if((j&i) > 0){
                res += cnt[j] * cnt[i];
            }
        }
    }
    for(int i = 0; i <= 1024; ++i){
        res += (cnt[i] * (cnt[i] - 1)) / 2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("RELATIVES.INP", "r", stdin);
    freopen("RELATIVES.OUT", "w", stdout);
    readData();
    ll res;
    res = relatives();
    cout << res;
    return 0;
}
