#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll m, n;
ll a[maxN];
ll sum = 0;

void readData(){
    cin >> m >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
}

ll candies(){
    sort(a, a + n);
    ll thatvong = sum - m;
    ll res = 0;
    if(thatvong <= 0) return 0;
    for(int i = 0; i < n; ++i){
        ll soNg = n - i;
        ll tv = min(a[i], thatvong / soNg);
        res += tv*tv;
        thatvong -= tv;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CANDIES.INP", "r", stdin);
    freopen("CANDIES.OUT", "w", stdout);
    readData();
    ll res;
    res = candies();
    cout << res;
    return 0;
}
