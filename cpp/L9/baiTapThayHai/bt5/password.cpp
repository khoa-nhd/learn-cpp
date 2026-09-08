#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n;
ll og[maxN];
struct input{
    ll val, idx;
    ll tongChuSo;
} a[maxN];

ll tinhTongChuSo(ll n){
    ll res = 0;
    while(n > 0){
        res += n % 10;
        n /= 10;
    }
    return res;
}

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].val;
        og[i] = a[i].val;
        a[i].idx = i;
        a[i].tongChuSo = tinhTongChuSo(a[i].val);
    }
}

bool cmp(input a, input b){
    if(a.tongChuSo == b.tongChuSo) return a.idx < b.idx;
    return a.tongChuSo < b.tongChuSo;
}

void password(){
    sort(a, a + n, cmp);
//    for(int i = 0; i < n; ++i) cout << a[i].tongChuSo <<  " ";
//    cout << "\n";
//    for(int i = 0; i < n; ++i) cout << a[i].val << " ";
//    cout << "\n";
    pair<ll, ll> res;
    ll minDiff = LLONG_MAX;
    res.first = LLONG_MAX;
    res.second = LLONG_MAX;
    ll prevIdx = 0;
    for(int i = 1; i < n; ++i){
        if(a[i].tongChuSo != a[prevIdx].tongChuSo){
            ll currDiff = a[i].tongChuSo - a[prevIdx].tongChuSo;
            ll minIdxCurr = min(a[i].idx, a[prevIdx].idx);
            ll maxIdxCurr = max(a[i].idx, a[prevIdx].idx);
            if(currDiff < minDiff){
                minDiff = currDiff;
                res.first = minIdxCurr;
                res.second = maxIdxCurr;
            } else if(minDiff == currDiff){
                if(res.first > minIdxCurr){
                    res.first = minIdxCurr;
                    res.second = maxIdxCurr;
                } else if(res.first == minIdxCurr && res.second > maxIdxCurr){
                    res.second = maxIdxCurr;
                }
            }
            prevIdx = i;
        }
    }
    cout << og[res.first] << og[res.second];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PASSWORD.INP", "r", stdin);
    freopen("PASSWORD.OUT", "w", stdout);
    readData();
    password();
    return 0;
}
