#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string n;
set<ull> d;

void xoa(ll len){
    for(int i = 0; i < n.size()-len+1; ++i){
        ull x = 0;
        for(int j = 0; j < i; ++j){
            x *= 10;
            x += n[j] - '0';
        }
        for(int j = i + len; j < n.size(); ++j){
            x *= 10;
            x += n[j] - '0';
        }
        d.insert(x);
    }
}

ll numset(){
    ll res = 0;
    for(int i = 1; i <= n.size()-1; ++i){
        xoa(i);
    }
    for(ull x : d){
//        cout << x << "\n";
        if(x % 3 == 0) res += 1;
    }
    ll sum = 0;
    for(char x : n){
        sum += x - '0';
    }
    if(sum % 3 == 0) res += 1;
    return res;
}

int main(){
    freopen("NUMSET.INP", "r", stdin);
    freopen("NUMSET.OUT", "w", stdout);
    cin >> n;
    ll res;
    res = numset();
    cout << res;
    return 0;
}
