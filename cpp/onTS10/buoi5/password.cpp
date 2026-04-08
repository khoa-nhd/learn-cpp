#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

bool check(ll i, ll j){
    if(j - i + 1 < 6) return false;
    int hoa = 0, thuong = 0, so = 0;
    while(i <= j){
      int a = (int)s[i];
      if('0' <= a && a <= '9'){
        so += 1;
      } else if('A' <= a && a <= 'Z'){
        hoa += 1;
      } else{
        thuong += 1;
      }
      i += 1;
    }
    if(hoa >= 1 && thuong >= 1 && so >= 1) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cin >> s;
    ll r = 5;
    ll res = 0;
    ll n = s.size();
    for(ll l = 0; l < n; ++l){
      while(!check(l, r) && r < n){
        r += 1;
      }
      res += n - r;
    }
    cout << res;
    return 0;
}
