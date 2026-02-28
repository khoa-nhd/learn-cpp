#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a;

int main(){
    cin >> n >> a;
    ll res = (((1 + a * (n-1)) + 1) * n) / 2;
    cout << res;
    return 0;
}
