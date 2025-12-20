#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll dp[maxN][maxN] = {};
ll n;
string s;

void palind(){
    for(int i = n - 1; i >= 0; --i){
        for(int j = i; j < n; ++j){
            if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
            else dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1;
        }
    }

//    for(int i = 0; i < n; ++i){
//        for(int j = 0; j < n; ++j){
//            cout << dp[i][j] << " ";
//        }
//        cout << "\n";
//    }

    ll i = 0;
    ll j = n-1;
    string l, r;
    while(i <= j){
        if(i == j){
            l.push_back(s[i]);
            break;
        }
        if(s[i]== s[j]){
            l.push_back(s[i]);
            r.push_back(s[j]);
            i += 1;
            j -= 1;
        } else if(dp[i+1][j] < dp[i][j-1]){
            l.push_back(s[i]);
            r.push_back(s[i]);
            i += 1;
        } else{
            l.push_back(s[j]);
            r.push_back(s[j]);
            j -= 1;
        }
    }

    cout << l;
    for(int i = r.size()-1; i >= 0; --i) cout << r[i];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PALIND.INP", "r", stdin);
    freopen("PALIND.OUT", "w", stdout);
    cin >> s;
    n = s.size();
    palind();
    return 0;
}
