#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int main(){
    cin >> n;
    ll res = 0;
    if(n >= 6) res += 6;
    if(n >= 28) res += 28;
    if(n >= 496) res += 496;
    if(n >= 8128) res += 8128;
    cout << res;
    return 0;
}
