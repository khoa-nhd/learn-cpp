#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

ll palind(string str, ll add){
    ll i = 0;
    ll j = str.size() - 1;
    while(i < j){
        if(i != j){
            string sub = str.substr(i, j);
            string str1, str2;
            str1 = sub.push_back(str[i]);
            str2 = str[j] + sub;
            ll temp1 = palind(str1, add+1);
            ll temp2 = palind(str2, add+1);
            add = min(temp1, temp2);
        }
    }
    return add;
}


int main(){
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);

    cin >> s;
    ll res;
    res = palind(s, 0);
    cout << res;
    return 0;
}
