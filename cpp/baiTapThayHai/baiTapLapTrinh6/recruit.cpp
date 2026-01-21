#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, ll> a[1005];
ll n;
ll prefix[1005] = {};
ll soQuanMua[1005] = {};

void readData(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

void prefixSum(){
    for(int i = 1; i <= n; ++i){
        prefix[i] = prefix[i-1] + a[i].first;
    }
}

ll recruit(){
    sort(a + 1, a + n + 1);
    prefixSum();
    ll curr = 0;
    for(int i = n; i >= 1; --i){
        while(soQuanMua[i] + curr + prefix[i-1] <= a[i].first - soQuanMua[i]) soQuanMua[i] += 1;
        curr += soQuanMua[i];
    }

    ll res = 0;
    for(int i = 1; i <= n; ++i){
        res += soQuanMua[i] * a[i].second;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("RECRUIT.INP", "r", stdin);
    freopen("RECRUIT.OUT", "w", stdout);
    readData();
    ll res = 0;
    res = recruit();
    cout << res;
    return 0;
}
