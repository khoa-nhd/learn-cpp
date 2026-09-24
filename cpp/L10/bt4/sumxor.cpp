#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[maxN];
ll b1[80] = {};
ll b0[80] = {};

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
            } else{
                b0[j] += 1;
            }
            t /= 2;
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 30; ++j){
            if(a[i] % 2 == 1){
                res += b0[j] * (1LL << j);
            } else{
                res += b1[j] * (1LL << j);
            }
            a[i] /= 2;
        }
    }
    cout << res/2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUMXOR.INP", "r", stdin);
    freopen("SUMXOR.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
