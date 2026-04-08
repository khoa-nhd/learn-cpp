#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    string x, y;
    cin >> x >> y;
    ll n = x.size();
    x += x;
    for(int i = 0; i < n; ++i){
      if(i + y.size() >= x.size()) break;
      string s = x.substr(i, y.size());
      if(s == y) cout << i+1 << " ";
    }
    return 0;
}
