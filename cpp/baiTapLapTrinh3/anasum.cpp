#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll anasum() {
    sort(a, a + n);
    ll tongDaySo = a[0];
    if(a[0] > 1){
        return 1;
    }
    for(int i = 1; i < n; ++i){
        if(tongDaySo+1 < a[i]){
            return tongDaySo + 1;
        } else{
            tongDaySo += a[i];
        }
    }
    return tongDaySo + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ANASUM.INP", "r", stdin);
    freopen("ANASUM.OUT", "w", stdout);
    readData();
    ll m;
    m = anasum();
    cout << m;
    return 0;
}
