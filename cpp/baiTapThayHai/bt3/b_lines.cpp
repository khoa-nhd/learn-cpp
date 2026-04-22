#include <bits/stdc++.h>
using namespace std;
#define maxN 100005
typedef long long ll;

ll m, n, k;
ll a[maxN] = {};

void readData(){
    cin >> m >> n >> k;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            int temp;
            cin >> temp;
            a[temp] += 1;
        }
    }
}

ll blines(){
    ll result = 0;
    sort(a, a + maxN, greater<ll>());
    for(int i = 0; i < k; ++i){
        result += a[i];
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("B_LINES.INP", "r", stdin);
    freopen("B_LINES.OUT", "w", stdout);
    readData();
    ll result;
    result = blines();
    cout << result;
    return 0;
}
