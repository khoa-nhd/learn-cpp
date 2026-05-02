#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, m;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

ll bpic(){
    vector<vector<ll>> dp(m+5, vector<ll>(n+5, 1e9));
    for(int i = 0; i < m; ++i){
        dp[i][a[i].first] = 0;
        ll cnt = 1;
        for(int j = a[i].first-1; j > 0; --j){
            dp[i][j] = cnt;
            cnt += 1;
        }
        cnt = 1;
        for(int j = a[i].first + 1; j < n - (a[i].second - a[i].first) + 1; ++j){
            dp[i][j] = cnt;
            cnt += 1;
        }
    }
    for(int i = 1; i < m; ++i){
        deque<ll> dq;
        vector<ll> minval(n+5);
        ll k = 1;
        ll ddt = a[i-1].second - a[i-1].first + 1;
        ll ddht = a[i].second - a[i].first + 1;
        for(int j = 1; j <= n - ddht + 1; ++j){
            while(k <= n - ddt + 1 && k <= j + ddht - 1){
                while(dq.size() > 0 && dp[i-1][k] <= dp[i-1][dq.back()]) dq.pop_back();
                dq.push_back(k);
                k += 1;
            }
            while(dq.size() > 0 && dq.front() < j - ddt + 1) dq.pop_front();
            if(dq.size() > 0) dp[i][j] += dp[i-1][dq.front()];
        }
    }
//    for(int i = 0; i < m; ++i){
//        for(int j = 1; j <= n; ++j){
//            cout << dp[i][j] << " ";
//        }
//        cout << "\n";
//    }
    ll res = LLONG_MAX;
    for(int i = 0; i <= n; ++i){
        res = min(res, dp[m-1][i]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BPIC.INP", "r", stdin);
    freopen("BPIC.OUT", "w", stdout);
    readData();
    ll res;
    res = bpic();
    cout << res;
    return 0;
}
