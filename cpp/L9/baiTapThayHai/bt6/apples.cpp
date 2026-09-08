#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, a;
ll c[25];

void readData(){
    cin >> n >> m >> a;
    for(int i = 0; i < a; ++i){
        cin >> c[i];
    }
}

ll apples(){
    ll res = 0;
    ll s = 1, e = m;
    for(int i = 0; i < a; ++i){
        if(s <= c[i] && e >= c[i]) continue;
        if(e < c[i]){
            res += c[i] - e;
            e = c[i];
            s = e - (m - 1);
        } else{
            res += s - c[i];
            s = c[i];
            e = s + m - 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("APPLES.INP", "r", stdin);
    freopen("APPLES.OUT", "w", stdout);
    readData();
    ll res;
    res = apples();
    cout << res;
    return 0;
}
