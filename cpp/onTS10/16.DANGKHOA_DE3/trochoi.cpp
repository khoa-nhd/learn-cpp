#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, m;
struct skill{
    ll s, e, idx;
} a[maxN];
ll maxVal = LLONG_MIN, ld = -1, vtri = -1;

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i].s >> a[i].e;
        a[i].idx = i;
        if(maxVal < a[i].e){
            maxVal = a[i].e;
            ld = a[i].s;
            vtri = i;
        }
    }
}

bool cmp(skill x, skill y){
    return x.s + x.e > y.s + y.e;
}

ll trochoi(){
    sort(a, a + n, cmp);
    ll res = 0;
    for(int i = 0; i < n && m > 0; ++i){
        if(a[i].s + a[i].e <= maxVal) break;
        if(vtri != a[i].idx){
            m -= 1;
            res += a[i].s + a[i].e;
        }
    }
    if(m > 0){
        res += ld;
        res += m * maxVal;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TROCHOI.INP", "r", stdin);
    freopen("TROCHOI.OUT", "w", stdout);
    readData();
    ll res;
    res = trochoi();
    cout << res;
    return 0;
}
