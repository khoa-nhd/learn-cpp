#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, m, s;
struct str{
    ll an, tt, diff;
    ll l, r;
} a[maxN];
bool an[maxN];
priority_queue<ll, vector<ll>, greater<ll>> pq1, pq2;

void readData(){
    cin >> n >> m >> s;
    for(int i = 0; i < n; ++i){
        cin >> a[i].an >> a[i].tt;
        a[i].diff = a[i].an - a[i].tt;
    }
}

bool cmp(str x, str y){
    return x.diff > y.diff;
}

void calPri(){
    ll t1 = 0, t2 = 0;
    for(int i = 0; i < m; ++i){
        pq1.push(a[i].an);
        t1 += a[i].an;
    }
    if(m > 0) a[m-1].l = t1;
    for(int i = m; i < n && m != 0; ++i){
        t1 = max(t1, t1 - pq1.top() + a[i].an);
        pq1.push(a[i].an);
        pq1.pop();
        a[i].l = t1;
    }
    for(int i = n-1; i > n - s - 1; --i){
        pq2.push(a[i].tt);
        t2 += a[i].tt;
    }
    a[n-s].r = t2;
    for(int i = n - s - 1; i >= 0 && s != 0; --i){
        t2 = max(t2, t2 - pq2.top() + a[i].tt);
        pq2.push(a[i].tt);
        pq2.pop();
        a[i].r = t2;
    }
}

ll schools(){
    sort(a, a + n, cmp);
    calPri();
    ll res = LLONG_MIN;
    for(int i = max(0LL, m - 1); i < n - s; ++i){
        res = max(res, a[i].l + a[i+1].r);
    }
//    for(int i = 0; i < n; ++i){
//        cout << a[i].an << " " << a[i].tt << " " << a[i].l << " " << a[i].r << "\n";
//    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SCHOOLS.INP", "r", stdin);
    freopen("SCHOOLS.OUT", "w", stdout);
    readData();
    ll res;
    res = schools();
    cout << res;
    return 0;
}
