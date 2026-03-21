 #include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define maxN 500005

 ll n, k, a[maxN];
 ll pre[maxN] = {};
 ll suf[maxN] = {};

 void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void prep(){
    for(int i = 0; i < n; i += k){
        pre[i] = a[i];
        for(int j = i+1; j-i < k && j <= n; ++j){
            pre[j] = __gcd(pre[j-1], a[j]);
        }
    }
//    for(int i = 0; i < n; ++i) cout << pre[i] << " ";
//    cout << "\n";
    for(int i = k-1; i < n; i += k){
        suf[i] = a[i];
        for(int j = i-1; i-j < k; --j){
            suf[j] = __gcd(suf[j+1], a[j]);
        }
    }
//    for(int i = 0; i < n; ++i) cout << suf[i] << " ";
}

ll sol(){
    ll res = LLONG_MIN;
    for(int i = 0; i < n; ++i){
        ll j = i + k - 1;
        if(j >= n) break;
        res = max(res, __gcd(suf[i], pre[j]));
    }
    return res;
}

 int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GCD.INP", "r", stdin);
    freopen("GCD.OUT", "w", stdout);
    readData();
    prep();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
