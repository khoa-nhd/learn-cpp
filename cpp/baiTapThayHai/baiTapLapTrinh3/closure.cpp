#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005
#define maxN2 100005

ll n, a[maxN], maxidx[maxN2] = {}, minidx[maxN2] = {}, dist[maxN2];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll closure(){
    for(int i = 0; i < n; ++i){
        maxidx[a[i]] = i;
    }
    for(int i = n-1; i >= 0; --i){
        minidx[a[i]] = i;
    }
    for(int i = 0; i < maxN2; ++i){
        dist[i] = maxidx[i] - minidx[i];
    }

    ll maxx = -1;
    for(int i = 0; i < maxN2; ++i){
        maxx = max(maxx, dist[i]);
    }
    return maxx+1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CLOSURE.INP", "r", stdin);
    freopen("CLOSURE.OUT", "w", stdout);
    readData();
    ll m;
    m = closure();
    cout << m;
    return 0;
}
