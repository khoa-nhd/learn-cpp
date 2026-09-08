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
      int cnt[30] = {};
      for(int i = 0; i < s.size(); ++i){
        cnt[s[i] - 'a'] += 1;
      }
      for(int i = 0; i < s.size(); ++i){
        if(cnt[s[i] - 'a'] == 1){
          cout << i+1 << "\n";
          break;
        }
        if(i == s.size() - 1) cout << -1 << "\n";
      }
    }
    return 0;
}
