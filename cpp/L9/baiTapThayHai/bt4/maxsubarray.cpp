#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll maxsubarray(){
    ll maxx = LLONG_MIN;
    ll current;
    for(int i = 0; i < n; ++i){
//        current += a[i]; sai vì không bắt đầu từ a[i]
//        maxx = max(current, maxx);
//        current = max(current, 0LL);
        current = max(a[i], a[i] + current);
        maxx = max(maxx, current);
    }
    return maxx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MAXSUBARRAY.INP", "r", stdin);
    freopen("MAXSUBARRAY.OUT", "w", stdout);
    readData();
    ll result;
    result = maxsubarray();
    cout << result;
    return 0;
}
