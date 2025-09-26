#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

string myreverse(string s){
    string result;
    for(int i = s.size()-1; i >= 0; --i){
        result += s[i];
    }
    return result;
}

ll mu10(int somu){
    ll result = 1;
    for(int i = 0; i < somu; ++i){
        result *= 10;
    }
    return result;
}


ll palindrome(ll n){
    ll sochuso = 1;
    ll sothutu = 0;

    while (true) {
        ll k = 9 * mu10((sochuso - 1) / 2);
        if (n <= k) break;
        n -= k;
        sochuso += 1;
    }

    int halfLen = (sochuso + 1) / 2;
    ll start = mu10(halfLen - 1);
    ll first = start + (n - 1);

    string result = to_string(first);
    result += myreverse(result.substr(0, sochuso/2));
    return stoll(result);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PALINDROME.INP", "r", stdin);
    freopen("PALINDROME.OUT", "w", stdout);
    cin >> n;
    ll m;
    m = palindrome(n);
    cout << m;
    return 0;
}
