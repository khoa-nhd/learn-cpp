#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
string s;

ll tim(ll st, ll e, char target){
    for(int i = st; i <= e; ++i){
        if(s[i] == target) return i;
    }
    return -1;
}

ll marbles(){
    ll res = 0;
    ll biDo = 0, biXanh = 0, biTrang = 0;
    pair<ll, ll> vd, vx, vt;
    for(int i = 0; i < n; ++i){
        if(s[i] == 'T') biTrang += 1;
        else if(s[i] == 'D') biDo += 1;
        else biXanh += 1;
    }
    vx = {0, biXanh-1};
    vt = {biXanh, biXanh + biTrang - 1};
    vd = {biXanh + biTrang, biXanh + biTrang + biDo - 1};

    for(int i = vx.first; i <= vx.second; ++i){
        ll td;
        if(s[i] == 'T'){
            td = tim(vt.first, vt.second, 'X');
            if(td == -1) td = tim(vd.first, vd.second, 'X');
        } else if(s[i] == 'D'){
            td = tim(vd.first, vd.second, 'X');
            if(td == -1) td = tim(vt.first, vt.second, 'X');
        }
        if(s[i] != 'X'){
            swap(s[i], s[td]);
            res += 1;
        }
    }
    for(int i = vt.first; i <= vt.second; ++i){
        ll td;
        if(s[i] == 'X'){
            td = tim(vx.first, vx.second, 'T');
            if(td == -1) td = tim(vd.first, vd.second, 'T');
        } else if(s[i] == 'D'){
            td = tim(vd.first, vd.second, 'T');
            if(td == -1) td = tim(vx.first, vx.second, 'T');
        }
        if(s[i] != 'T'){
            swap(s[i], s[td]);
            res += 1;
        }
    }
    return res;
}

int main(){
    freopen("MARBLES.INP", "r", stdin);
    freopen("MARBLES.OUT", "w", stdout);
    cin >> n >> s;
    ll res;
    res = marbles();
    cout << res;
    return 0;
}
