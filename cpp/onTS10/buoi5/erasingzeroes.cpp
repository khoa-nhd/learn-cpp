#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
      string s;
      cin >> s;
      ll d = -1;
      ll c = -1;
      ll n = s.size();
      for(int i = 0; i < n; ++i){
        if(s[i] == '1'){
          if(d == -1) d = i;
          c = i;
        }
      }
      if(d == -1){
        cout << 0 << "\n";
        continue;
      }
      ll res = 0;
      for(int i = d; i <= c; ++i){
        if(s[i] == '0') res += 1;
      }
      cout << res << "\n";
    }
    return 0;
}
