#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("WORDS.INP", "r", stdin);
    freopen("WORDS.OUT", "w", stdout);
    string s;
    ll words = 0, maxLen = LLONG_MIN;
    while(cin >> s){
        words += 1;
        maxLen = max(maxLen, (ll)s.size());
    }
    cout << words << " " << maxLen;
    return 0;
}
