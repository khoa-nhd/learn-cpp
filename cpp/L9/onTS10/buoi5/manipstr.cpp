#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    ll  q;
    cin >> q;
    for(int i = 0; i < q; ++i){
      ll n;
      string s, t;
      cin >> n;
      cin >> s >> t;
      ll idx1 = -1;
      ll idx2 = -1;
      bool no = false;
      for(int i = 0; i < n; ++i){
        if(s[i] != t[i]){
          if(idx1 == -1) idx1 = i;
          else if(idx2 == -1) idx2 = i;
          else no = true;
        }
      }
      if(no){
        cout << "No\n";
      } else{
        if(idx1 == -1 && idx2 == -1) cout << "Yes\n";
        else if(idx1 != -1 && idx2 == -1) cout << "No\n";
        else if(s[idx1] == s[idx2] && t[idx1] == t[idx2]) cout << "Yes\n";
        else cout << "No\n";
      }
    }
    return 0;
}
