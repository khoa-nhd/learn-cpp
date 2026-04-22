#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    string a, b;
    cin >> a >> b;
    if(b.size() < a.size()){
        cout << "No";
    } else{
        string s = b.substr(0, a.size());
        if(a == s) cout << "Yes";
        else cout << "No";
    }
    return 0;
}
