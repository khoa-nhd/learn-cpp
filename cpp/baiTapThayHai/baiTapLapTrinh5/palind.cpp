#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

string s;
ll dp[maxN][maxN] = {};

void palind(){
    for(int len = 2; len <= s.size(); ++len){
        for(int i = 0; i + len - 1 < s.size(); ++i){
            int j = i + len - 1;
            if(s[i] == s[j]){
                dp[i][j] = dp[i+1][j-1];
            } else{
                dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
            }
        }
    }

    vector<char> res(s.size() + dp[0][s.size()-1]);
    string l, r;
    ll i = 0;
    ll j = s.size() - 1;
    while(i <= j){
        if(i == j){
            l.push_back(s[i]);
            break;
        }
        if(s[i] == s[j]){
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
    freopen("PALIND.INP", "r", stdin);
    freopen("PALIND.OUT", "w", stdout);
    cin >> s;
    palind();
    return 0;
}
