#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> bigint;

ll n;
bigint d[2005] = {};

bigint operator + (bigint a, bigint b){
    int c = 0;
    bigint res;
    int i = 0;
    while(i < a.size() || i < b.size()){
        if(i < a.size()) c += a[i];
        if(i < b.size()) c += b[i];
        i += 1;
        res.push_back(c%10);
        c /= 10;
    }
    if(c > 0) res.push_back(c);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BOOLSYS.INP", "r", stdin);
    freopen("BOOLSYS.OUT", "w", stdout);
    cin >> n;
    if(n == 1){
        cout << 6;
        return 0;
    }
    if(n == 2){
        cout << 10;
        return 0;
    }
//    cout << 6 << "\n" << 10 << "\n";
    d[1].push_back(6);
    d[2].push_back(0);
    d[2].push_back(1);
    for(int i = 3; i <= n; ++i){
        d[i] = d[i-1] + d[i-2];
//        cout << d[i] << "\n";
    }
    for(int i = d[n].size()-1; i >= 0; --i){
        cout << d[n][i];
    }
    return 0;
}
