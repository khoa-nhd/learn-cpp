#include <bits/stdc++.h>
using namespace std;
#define maxN 100005
typedef long long ll;

ll a[maxN], n;

void readData() {
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll findMin(ll b[], ll num){
    ll minn = b[0];
    for(int i = 0; i <= num; ++i){
        if(b[i] < minn){
            minn = b[i];
        }
    }
    return minn;
}

ll bonus() {
    ll result = 0;
    sort(a, a+n);
    ll val[maxN], last = 0;
    val[0] = a[0];
    for(int i = 1; i < n; ++i){
        if(a[i-1] == a[i]){
            val[last] += a[i];
        } else {
            last += 1;
            val[last] = a[i];
        }
    }
    ll minVal = findMin(val, last);
    for(int i = 0; i <= last; ++i){
        result += val[i];
    }
    result -= minVal;
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);
    readData();
    ll m;
    m = bonus();
    cout << m;
    return 0;
}
