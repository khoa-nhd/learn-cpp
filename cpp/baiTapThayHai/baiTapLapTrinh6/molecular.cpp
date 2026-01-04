#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll a[4] = {1, 16, 14, 12};

ll so(char x){
    if(x == 'H') return 0;
    if(x == 'O') return 1;
    if(x == 'N') return 2;
    if(x == 'C') return 3;
    return -1;
}

ll molecular(){
    ll res = 0;
    for(int i = 0; i < s.size(); ++i){
        ll num = so(s[i]);
        if(num == -1){
            res += a[so(s[i-1])] * ((s[i] - '0') - 1);
        } else{
            res += a[so(s[i])];
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MOLECULAR.INP", "r", stdin);
    freopen("MOLECULAR.OUT", "w", stdout);
    cin >> s;
    ll res;
    res = molecular();
    cout << res;
    return 0;
}
