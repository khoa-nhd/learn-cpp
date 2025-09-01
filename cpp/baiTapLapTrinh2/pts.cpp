#include <bits/stdc++.h>
using namespace std;
#define maxN 100005
typedef long long ll;

ll n, m, a[maxN], b[maxN];

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> b[i];
    }
}

ll pts(){
    ll result = 0;
    sort(a, a+n);
    sort(b, b+n);
    for(int i = 0; i <= m; ++i){
        auto it = lower_bound(a, a+n, b[i]);
        result += it - a;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PTS.INP", "r", stdin);
    freopen("PTS.OUT", "w", stdout);
    readData();
    ll m;
    m = pts();
    cout << m;
    return 0;
}
