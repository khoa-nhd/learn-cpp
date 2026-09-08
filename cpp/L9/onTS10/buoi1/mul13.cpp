#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll l, r;
    cin >> l >> r;
    ll num = (r - l) + 1;
    ll sum = (r + l) * num / 2;
    ll num13 = r/13 - (l-1)/13;
    ll r13 = (r / 13) * 13;
    ll l13 = ((l + 12) / 13) * 13;
    ll sum13 = (r13 + l13) * num13 / 2;
    cout << sum - sum13;
    return 0;
}
