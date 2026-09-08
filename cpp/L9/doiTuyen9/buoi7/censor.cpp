#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

string s, t;
pair<int, int> nhay[maxN] = {};

void censor(){
    string res;
    ll n = s.size();
    ll i = 0;
    for(int i = 0; i < n; ++i){
        nhay[i] = {i-1, i+1};
    }
    while(i < n){
        if(s[i] == t[0]){
            ll bd = i;
            for(int j = 0; j < t.size(); ++j){
                if(s[i] != t[j]) break;
                if(j == t.size() - 1){
                    nhay[bd-1].second = i + 1;
                    nhay[i+1].first = bd-1;
                    i += 1;
                    for(int k = 0; k < t.size() + 3; ++k){
                        i = nhay[i].first;
                    }
                }
                i = nhay[i].second;
            }
        } else i = nhay[i].second;
    }
    i = 0;
    while(i < n){
        res.push_back(s[i]);
        i = nhay[i].second;
    }
    if(res[0] = ' ') res = res.substr(1);
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CENSOR.INP", "r", stdin);
    freopen("CENSOR.OUT", "w", stdout);
    cin >> s >> t;
    s = ' ' + s;
    censor();
    return 0;
}
