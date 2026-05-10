#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
string s;

ll sub1(){
    set<string> se;
    ll res = 0;
    for(int len = 1; len <= n; ++len){
        for(int i = 0; i + len - 1 < n; ++i){
            string temp = s.substr(i, len);
            if(se.find(temp) != se.end()) res = max(res, (ll)len);
            se.insert(temp);
        }
    }
    return res;
}

bool check(ll x){
    set<deque<char>> se;
    deque<char> curr;
    for(int i = 0; i < x; ++i){
        curr.push_back(s[i]);
    }
    se.insert(curr);
    for(int i = x; i < n; ++i){
        curr.push_back(s[i]);
        curr.pop_front();
        if(se.find(curr) != se.end()) return true;
        se.insert(curr);
    }
    return false;
}

ll sub2(){
    ll d = 1, c = n;
    ll res = 0;
    while(d <= c){
        ll half = (d + c) / 2;
        if(check(half)){
            d = half + 1;
            res = half;
        } else{
            c = half - 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);
    cin >> n >> s;
    ll res = 0;
    res = sub2();
    cout << res;
    return 0;
}
