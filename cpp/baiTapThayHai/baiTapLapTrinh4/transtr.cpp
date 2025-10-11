#include <bits/stdc++.h>
using namespace std;

string n;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TRANSTR.INP", "r", stdin);
    freopen("TRANSTR.OUT", "w", stdout);
    cin >> n >> s;
    int i = n.size() - 1;
    long long soLan = 0;
    long long x = 1;
    while(i >= 0){
        soLan += (n[i] - '0') * x % s.size();
        soLan %= s.size();
        x *= 10;
        x %= s.size();
        i -= 1;
    }
    string temp = s.substr(0, soLan);
    s.erase(0, soLan);
    cout << s << temp;
    return 0;
}
