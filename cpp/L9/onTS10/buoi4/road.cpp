#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, k, a[maxN];
ll pre[maxN];
map<ll, ll> m;

void readData(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i] -= k;
    }
}

void sol(){
    pre[0] = 0;
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i-1] + a[i];
    }
    ll maxDist = 0;
    ll u = 0;
    for(int i = 0; i <= n; ++i){
        if(m.find(pre[i]) == m.end()){
            m[pre[i]] = i;
        } else{
            ll dist = i - m[pre[i]];
            if(maxDist < dist){
                maxDist = dist;
                u = m[pre[i]]+1;
            }
        }
    }
    if(maxDist == 0){
        cout << 0;
    } else{
        cout << u << " " << maxDist;
    }
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
