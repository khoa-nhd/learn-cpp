#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    for(int i = 0; i < n; ++i){
      string temp;
      cin >> temp;
      if(temp.size() <= 10) cout << temp << "\n";
      else cout << temp[0] << temp.size() - 2 << temp.back() << "\n";
    }
    return 0;
}
