#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t;
string s;

bool check(){
    if(s.size() % 2 == 1) return false;
    ll mo = 0;
    ll maxMo = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '('){
            mo += 1;
            maxMo += 1;
        } else if(s[i] == ')'){
            mo -= 1;
            maxMo -= 1;
        } else{
            if(mo == 0) mo += 1;
            else mo -= 1;
            maxMo += 1;
        }
        if(mo < 0) mo = 1;
        if(maxMo < 0) return false;
    }
    return mo == 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> s;
        if(check()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
