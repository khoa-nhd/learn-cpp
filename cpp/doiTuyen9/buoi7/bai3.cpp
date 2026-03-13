#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10005

string s;
ll pre[maxN] = {};

ll bai3(){
    ll res = 0;
    int n = s.size();
    for(int i = 1; i <= n; ++i){
        if(s[i-1] - '0' > 9) pre[i] = 1;
        else pre[i] = -1;
    }
    for(int i = 1; i <= n; ++i){
        pre[i] += pre[i-1];
    }
    for(int len = 1; len <= n; ++len){
        for(int i = 1; i <= n; ++i){
            int j = i + len - 1;
            if(j > n) break;
            if(pre[j] - pre[i-1] > 0) res += 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);
    cin >> s;
    ll res;
    res = bai3();
    cout << res;
    return 0;
}
