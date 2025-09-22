#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> b;
ll sothutu = 0;

void addpalindrome(ll from, ll to, ll sochuso){
    for(int i = from; i <= to; ++i){
        string temp = to_string(i);
        temp += temp.substr(0, sochuso/2);
        b.push_back(stoll(temp));
        sothutu += 1;
    }
}

ll palindrome(ll n){
    ll sochuso = 1;
    ll from, to;
    while(sothutu <= n){
        from = 1;
        to = 9;
        for(int i = 1; i < (sochuso+1)/2; ++i){
            from = from*10;
            to = to*10 + 9;
        }

        addpalindrome(from, to, sochuso);
        sochuso += 1;
    }
    return b[n-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PALINDROME.INP", "r", stdin);
    freopen("PALINDROME.OUT", "w", stdout);
    ll n;
    cin >> n;
    ll m;
    m = palindrome(n);
    cout << m;
    return 0;
}
