#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

void h_shakes(){
    ll num = 0;
    ll tg = 0;
    ll cnt = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'R') cnt += 1;
        else{
            num += cnt;
            if(cnt > 0) tg = max(tg + 1, cnt);
        }
    }
    cout << tg << " " << num;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("H_SHAKES.INP", "r", stdin);
    freopen("H_SHAKES.OUT", "w", stdout);
    cin >> s;
    h_shakes();
    return 0;
}
