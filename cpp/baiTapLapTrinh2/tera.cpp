#include <bits/stdc++.h>
using namespace std;
#define maxN 1005
typedef long long ll;

ll n, l;
ll xanh[maxN], dor[maxN], tim[maxN], vang[maxN];

void readData(){
    cin >> n >> l;
    for(int i = 0; i < n; ++i){
        cin >> xanh[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> dor[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> tim[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> vang[i];
    }
}

ll teraa(){
    ll result = 0;
    vector<ll> xanhdo, timvang;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            xanhdo.push_back(xanh[i] + dor[j]);
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            timvang.push_back(tim[i] + vang[j]);
        }
    }
    sort(timvang.begin(), timvang.end());
    for (ll sum : xanhdo) {
        ll target = l - sum;
        auto range = equal_range(timvang.begin(), timvang.end(), target);
        result += distance(range.first, range.second);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TERA.INP", "r", stdin);
    freopen("TERA.OUT", "w", stdout);
    readData();
    ll m;
    m = teraa();
    cout << m;
    return 0;
}
