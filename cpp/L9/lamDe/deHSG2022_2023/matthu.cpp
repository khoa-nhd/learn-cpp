#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, k, x;
string s;
string a[505] = {};

void readData(){
    cin >> n >> m >> k >> x;
    cin >> s;
    for(int i = 0; i < m; ++i){
        cin >> a[i];
    }
}

void matthu(){
    for(int i = 0; i < m; ++i){
        sort(a[i].begin(), a[i].end());
    }
    for(int i = 0; i < n; ++i){
        if(s[i] != '#'){
            cout << s[i];
        } else{
            cout << a[0][x-1];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();
    matthu();
    return 0;
}
