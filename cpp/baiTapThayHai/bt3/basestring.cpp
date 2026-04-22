#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a, b;
bool laXauCoSo = false;

void readData(){
    cin >> a >> b;
}

bool check(ll k, string s){
    string base = s.substr(0, k);
    //cout << "s: " << s << " k: " << k << "\n";
    for(int i = 0; i < s.size(); ++i){
        //cout << "s%: " << s[i%k] << " base%: " << base[i%k] << "\n";
        //cout << "i%k: " << i%k << " base.size: " << base.size() << "\n";
        if(s[i] != base[i%k]){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BASESTRING.INP", "r", stdin);
    freopen("BASESTRING.OUT","w", stdout);
    readData();
    ll k = __gcd(a.size(), b.size());
    if(check(k, a) && check(k, b)){
        for(int i = 0; i < k; ++i){
            if(a[i] != b[i]){
                cout << "NO";
                return 0;
            }
        }
        for(int i = 0; i < k; ++i){
            cout << a[i];
        }
    } else{
        cout << "NO";
    }
    return 0;
}
