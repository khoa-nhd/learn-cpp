#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void monitor(){
    unordered_map<ll, ll> m;
    ll maxx = LLONG_MIN, id;
    for(int i = 0; i < n; ++i){
        if(m.find(a[i]) == m.end()){
            m[a[i]] = i;
        } else{
            ll dist = i - m[a[i]] + 1;
            if(maxx < dist){
                maxx = dist;
                id = a[i];
            }
        }
    }
    cout << id << "\n" << maxx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MONITOR.INP", "r", stdin);
    freopen("MONITOR.OUT", "w", stdout);
    readData();
    monitor();
    return 0;
}
