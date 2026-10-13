#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n = 0;
int a[maxN] = {};

void readData(){
    string s;
    cin >> s;
    ll i = 0;
    for(char x : s){
        a[i] = s[i] - '0';
        i += 1;
    }
    n = s.size();
}

void sol(){
//    for(int i = 0; i < n; ++i) cout << a[i];
//    cout << "\n";
    ll tong = 0;
    ll so0 = 0;
    for(int i = 0; i < n; ++i){
        tong += a[i];
        so0 += (a[i] == 0);
    }
    if(so0 == 0 || tong % 3 != 0){
        cout << -1;
        return;
    }
    sort(a, a + n, greater<int>());
    for(int i = 0; i < n; ++i) cout << a[i];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MUL30.INP", "r", stdin);
    freopen("MUL30.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
