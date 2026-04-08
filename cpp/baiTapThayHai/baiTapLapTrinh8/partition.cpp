#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll l, n, a[maxN];
multiset<ll> ms;

void readData(){
    cin >> l >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];

    }
}

ll sol(){
    sort(a, a + n)
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();

    return 0;
}
