#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
string s;
ll cntbd[4] = {};

ll doi(char x){
    if(x == 'A') return 0;
    else if(x == 'T') return 1;
    else if(x == 'G') return 2;
    else return 3;
}

void dem(){
    for(int i = 0; i < n; ++i){
        cntbd[doi(s[i])] += 1;
    }
}

bool checkPossible(ll x){
    ll cnt[4] = {};
    for(int i = 0; i < x; ++i){
        cnt[doi(s[i])] += 1;
    }
    ll i = 0, j = x-1;
    while(j < n){
        ll cnt2[4] = {};
        for(int i = 0; i < 4; ++i){
            cnt2[i] = cntbd[i] - cnt[i];
        }
        ll tong = 0;
        for(int i = 0; i < 4; ++i){
            tong += n/4 - cnt2[i];
            if(cnt2[i] > n/4) break;
            if(i == 3 && tong <= x) return true;
        }
        cnt[doi(s[i])] -= 1;
        i += 1;
        j += 1;
        cnt[doi(s[j])] += 1;
    }
    return false;
}

ll gene(){
    ll lo = 0;
    ll hi = n;
    ll res = -1;
    while(lo <= hi){
        ll half = (lo + hi) / 2;
        if(checkPossible(half)){
            res = half;
            hi = half - 1;
        } else{
            lo = half + 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GENE.INP", "r", stdin);
    freopen("GENE.OUT", "w", stdout);
    cin >> n >> s;
    dem();
    ll res;
    res = gene();
    cout << res;
    return 0;
}
