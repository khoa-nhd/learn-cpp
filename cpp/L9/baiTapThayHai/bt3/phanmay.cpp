#include <bits/stdc++.h>
using namespace std;
#define maxN 100005
typedef long long ll;

ll n;
ll a[maxN], b[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
    }
}

ll phanmay(){
    sort(a, a + n);
    sort(b, b + n);
    ll i = 0, j = 0, current = 0, maxx = 0;
    while (i < n && j < n) {
        if (a[i] < b[j]) {
            current += 1;
            maxx = max(maxx, current);
            i++;
        } else {
            current--;
            j++;
        }
    }
    return maxx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PHANMAY.INP", "r", stdin);
    freopen("PHANMAY.OUT", "w", stdout);
    readData();
    ll m;
    m = phanmay();
    cout << m;
    return 0;
}
