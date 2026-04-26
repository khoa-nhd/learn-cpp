#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll dp[205][205];

void correct(){
    ll m = -1e9;
    ll n = s.size();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            dp[i][j] = m;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(dp[i][j] < 0) continue;
            if(j + 1 <= n) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + (s[i] == '('));
            if(j - 1 >= 0) dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j] + (s[i] == ')'));
        }
    }
    string res;
    ll i = n;
    ll j = 0;
    while(i > 0){
        if(j > 0 && dp[i][j] == dp[i-1][j-1] + (s[i-1] == '(')){
            res.push_back('(');
            j -= 1;
        } else{
            res.push_back(')');
            j += 1;
        }
        i -= 1;
    }
    reverse(res.begin(), res.end());
    cout << n - dp[n][0] << "\n" << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CORRECT.INP", "r", stdin);
    freopen("CORRECT.OUT", "w", stdout);
    cin >> s;
    correct();
    return 0;
}
