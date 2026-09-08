#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

void correct(){
    ll mo = 0;
    ll n = s.size();
    string res;
    for(int i = 0; i < n; ++i){
        if(s[i] == '('){
            res.push_back(s[i]);
            mo += 1;
        } else{
            if(mo > 0){
                mo -= 1;
                res.push_back(')');
            } else{
                mo += 1;
                res.push_back('(');
            }
        }
    }
    for(int i = n-1; i >= 0; --i){
        if(mo == 0) break;
        if(res[i] == '('){
            res[i] = ')';
            mo -= 2;
        }
    }
    ll khac = 0;
    for(int i = 0; i < n; ++i){
        khac += (res[i] != s[i]);
    }
    cout << khac << "\n";
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CORRECT.INP", "r", stdin);
    freopen("CORRECT.OUT", "w", stdout);
    cin >> s;
    correct();
    return 0;
}
