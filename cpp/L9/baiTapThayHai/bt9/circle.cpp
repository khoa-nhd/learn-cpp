#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10005

ll n;
pair<ll, ll> xanh[maxN], dor[maxN];
ll distXanh[maxN], distDo[maxN];

ll distmu2(pair<ll, ll> x){
    return x.first * x.first + x.second * x.second;
}

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> xanh[i].first >> xanh[i].second;
        distXanh[i] = distmu2(xanh[i]);
    }
    for(int i = 0; i < n; ++i){
        cin >> dor[i].first >> dor[i].second;
        distDo[i] = distmu2(dor[i]);
    }
}

ll cnt(ll dist[], ll dd){
    ll d = 0, c = n;
    ll res = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(dist[half] <= dd){
            d = half + 1;
            res = half;
        } else{
            c = half - 1;
        }
    }
    return res + 1;
}

bool check(ll dd){
    return cnt(distDo, dd) == cnt(distXanh, dd);
}

ll circle(){
    ll res = LLONG_MAX;
    sort(distDo, distDo + n);
    sort(distXanh, distXanh + n);
    for(int i = 0; i < n; ++i){
        ll d = distmu2(xanh[i]);
        if(check(d)) res = min(res, d);
    }
    for(int i = 0; i < n; ++i){
        ll d = distmu2(dor[i]);
        if(check(d)) res = min(res, d);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CIRCLE.INP", "r", stdin);
    freopen("CIRCLE.OUT", "w", stdout);
    readData();
    ll res = circle();
    double ans = sqrt(res);
    cout << fixed << setprecision(6) << ans;
    return 0;
}
