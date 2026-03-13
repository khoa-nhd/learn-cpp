#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
string s;
ll cnt[26] = {};

bool check(){
    for(int i = 0; i < 26; ++i){
        if(cnt[i] > k) return false;
    }
    return true;
}

void substring(){
    ll maxLen = 0, maxIdx = -1;
    ll l = 0, r = 0;
    while(r < n){

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    cin >> n >> k >> s;

    return 0;
}
