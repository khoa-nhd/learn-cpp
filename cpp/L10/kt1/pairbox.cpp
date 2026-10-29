#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void sol(){
    ll nguong = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] == 0){
            cout << 0;
            return;
        }
        nguong += a[i] - 1;
    }
    cout << nguong + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PAIRBOX.INP", "r", stdin);
    freopen("PAIRBOX.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
