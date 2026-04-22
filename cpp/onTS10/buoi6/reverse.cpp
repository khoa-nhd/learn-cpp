#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

string s;
ll m, a[maxN];
ll dao[maxN] = {};

void readData(){
    cin >> s >> m;
    for(int i = 0; i < m; ++i){
        cin >> a[i];
    }
}

void sol(){
    ll n = s.size();
    for(int i = 0; i < m; ++i){
        dao[a[i]-1] += 1;
        dao[n-a[i]+1] -= 1;
    }
    for(int i = 1; i < n; ++i) dao[i] += dao[i-1];
    for(int i = 0; i < n; ++i) dao[i] %= 2;
    ll i = 0, j = n-1;
    while(i < j){
        if(dao[i] == 1){
            swap(s[i], s[j]);
        }
        i += 1;
        j -= 1;
    }
    cout << s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
