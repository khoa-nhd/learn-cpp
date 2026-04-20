#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, d, a[maxN];

void readData(){
    cin >> n >> d;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        a[i] /= d;
    }
}

ll vines(){
    ll maxReach = 0;
    for(int i = 0; i < n; ++i){
        if(i > maxReach) break;
        maxReach = max(i + a[i], maxReach);
    }
    maxReach = min(maxReach, n-1);
    return maxReach + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("VINES.INP", "r", stdin);
    freopen("VINES.OUT", "w", stdout);
    readData();
    ll res;
    res = vines();
    cout << res;
    return 0;
}
