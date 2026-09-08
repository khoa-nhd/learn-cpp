#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

struct all{
    ll vt, qd, td;
} arr[maxN];
ll a, b, t;
ll n, q;

void readData(){
    cin >> n >> t >> q >> a >> b;
    arr[0].qd = 0;
    arr[0].td = 0;
    arr[0].vt = a;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i].td;
        cin >> arr[i].vt;
        if(arr[i].vt == 1) arr[i].vt = a;
        else arr[i].vt = b;
        arr[i].qd = arr[i-1].qd + arr[i-1].vt*(arr[i].td - arr[i-1].td);
//        cout << arr[i].qd << " ";
    }
    arr[n+1].qd = arr[n].qd + arr[n].vt*(t - arr[n].td);
    arr[n+1].td = t;
//    cout << arr[n+1].qd << "\n";
}

ll caldist(ll x){
    ll d = 0, c = n + 1;
    ll diem = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(arr[half].td <= x){
            diem = half;
            d = half + 1;
        } else{
            c = half - 1;
        }
    }
    ll res = arr[diem].qd;
    res += arr[diem].vt * (x-arr[diem].td);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    for(int i = 0; i < q; ++i){
        ll l, r;
        cin >> l >> r;
        cout << caldist(r) - caldist(l) << "\n";
    }
    return 0;
}
