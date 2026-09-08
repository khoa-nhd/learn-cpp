#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100000

ll n, a[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

void tbc(){
    for(int i = 0; i <= n; ++i){
        a[i] = a[i] * i;
    }
    for(int i = 1; i <= n; ++i){
        cout << a[i] - a[i-1] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();
    tbc();
    return 0;
}
