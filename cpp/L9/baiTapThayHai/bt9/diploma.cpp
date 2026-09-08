#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN];
ll sum = 0;

void readData(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        sum += a[i];
    }
}

bool check(ll k){
    deque<ll> dq;
    ll minVal[maxN];
    ll pre[maxN] = {};
    for(int i = 1; i <= n; ++i){
        while(dq.size() > 0 && dq.front() < i - k + 1) dq.pop_front();
        while(dq.size() > 0 && a[i] < a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        minVal[i] = a[dq.front()];
        pre[i] = pre[i-1] + a[i];
    }
    for(int i = k; i <= n; ++i){
        ll s = pre[i] - pre[i-k] - minVal[i];
        if(s*2 >= sum) return true;
    }
    return false;
}

ll diploma(){
    if(n == 1) return 1;
    ll d = 1, c = n;
    ll res = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(check(half)){
            c = half - 1;
            res = half;
        } else{
            d = half + 1;
        }
    }
    return res-1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DIPLOMA.INP", "r", stdin);
    freopen("DIPLOMA.OUT", "w", stdout);
    readData();
    ll res;
    res = diploma();
    cout << res;
    return 0;
}
