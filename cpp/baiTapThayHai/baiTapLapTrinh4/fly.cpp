#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005
#define maxN2 1000005

ll n, h[maxN], a[maxN];
ll sumEnergy[maxN2] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void fly(){
    ll tong = 0;
    for(int i = 0; i < n; ++i){
        tong += a[i];
    }

    for(int i = 0; i < n; ++i){
        sumEnergy[h[i]] += a[i];
    }

    ll maxx = LLONG_MIN;
    ll maxH;
    for(int i = 0; i < maxN2; ++i){
        if(maxx < sumEnergy[i]){
            maxx = sumEnergy[i];
            maxH = i;
        }
    }
    cout << maxH << " " << tong - maxx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FLY.INP", "r", stdin);
    freopen("FLY.OUT", "w", stdout);
    readData();
    fly();
    return 0;
}
