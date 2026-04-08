#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll res = 0;
    for(int i = 0; i < n; ++i){
      string temp;
      cin >> temp;
      if(temp.back() == '+' || temp[0] == '+') res += 1;
      else res -= 1;
    }
    cout << res;
    return 0;
}
