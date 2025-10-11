#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k;
string s;
ll soluongmau[26] = {};

ll tongmau(){
    ll result = 0;
    for(int i = 0; i < 26; ++i){
        if(soluongmau[i] > 0){
            result += 1;
        }
    }
    return result;
}

ll beads(){
    if(k == 1){
        return 1;
    }
    ll result = LLONG_MAX;
    ll d = 0, c = 1;
    int mau = 0;
    mau = (int)s[0] - 97;
    soluongmau[mau] += 1;
    mau = (int)s[1] - 97;
    soluongmau[mau] += 1;
    ll n = s.size();
    while(c < n){
        if(tongmau() >= k){
            result = min(result, c - d + 1);
            soluongmau[(int)s[d] - 97] -= 1;
            d += 1;
        } else{
            c += 1;
            if(c < n){
                soluongmau[(int)s[c] - 97] += 1;
            }
        }
    }
    if(result == LLONG_MAX){
        return -1;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BEADS.INP", "r", stdin);
    freopen("BEADS.OUT", "w", stdout);
    cin >> s;
    cin >> k;
    ll m;
    m = beads();
    cout << m;
    return 0;
}
