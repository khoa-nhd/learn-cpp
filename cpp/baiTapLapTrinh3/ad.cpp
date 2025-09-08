#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ad(string a, string b){
    int mot[26] = {}, hai[26] = {};
    ll result = 0;
    for(char c : a){
        mot[(int)c - 97] += 1;
    }
    for(char c : b){
        hai[(int)c - 97] += 1;
    }
    for(int i = 0; i < 26; ++i){
        result += abs(mot[i] - hai[i]);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("AD.INP", "r", stdin);
    freopen("AD.OUT", "w", stdout);
    string a, b;
    cin >> a >> b;
    ll m;
    m = ad(a, b);
    cout << m;
    return 0;
}
