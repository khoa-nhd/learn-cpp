#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll n;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cin >> n;
    cin >> s;
    ll res = 1;
    for(int i = 0; i < n; ++i){
      ll l = i-1, r = i+1;
      while(!(l < 0 || r >= n) && s[l] == s[r]){
        res = max(res, r - l + 1);
        l -= 1;
        r += 1;
      }
      l = i;
      r = i+1;
      while(!(l < 0 || r >= n) && s[l] == s[r]){
        res = max(res, r - l + 1);
        l -= 1;
        r += 1;
      }
    }
    cout << res;
    return 0;
}
