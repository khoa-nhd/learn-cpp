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
      ll n, k;
      cin >> n >> k;
      string s;
      cin >> s;

      if(n == 1){
        if(k >= 1) cout << 0 << "\n";
        else cout << s << "\n";
        continue;
      }
      if(k == 0){
        cout << s << "\n";
        continue;
      }

      vector<int> res;
      res.push_back(1);
      if(s[0] != '1') k -= 1;
      for(int i = 1; i < n; ++i){
        if(k > 0 && s[i] != '0'){
          res.push_back(0);
          k -= 1;
        } else{
          res.push_back(s[i] - '0');
        }
      }
      for(int i = 0; i < n; ++i) cout << res[i];
      cout << "\n";
    }
    return 0;
}
