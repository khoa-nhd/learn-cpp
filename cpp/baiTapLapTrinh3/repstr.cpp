#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll repstr(string s, ll n){
    ll numa = 0, result = 0, doDai = s.size();
    for(char c : s){
        if(c == 'a'){
            numa += 1;
        }
    }
    result += numa * (n / doDai);

    int le = n % doDai;
    for(int i = 0; i < le; ++i){
        if(s[i] == 'a'){
            result += 1;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("REPSTR.INP", "r", stdin);
    freopen("REPSTR.OUT", "w", stdout);

    string s;
    ll n;
    ll m;
    cin >> s >> n;
    m = repstr(s, n);
    cout << m;

    return 0;
}
