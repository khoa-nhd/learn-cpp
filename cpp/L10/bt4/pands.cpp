#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n;
ll a[maxN];
ll b1[80] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void sol(){
    unsigned long long res = 0;
    for(int i = 0; i < n; ++i){
        ll t = a[i];
        for(int j = 0; j < 30; ++j){
            if(t % 2 == 1){
                b1[j] += 1;
            }
            t /= 2;
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 30; ++j){
            if(a[i] % 2 == 1){
                res += (b1[j]-1) * (1LL << j);
            }
            a[i] /= 2;
        }
    }
    cout << res/2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PANDS.INP", "r", stdin);
    freopen("PANDS.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
