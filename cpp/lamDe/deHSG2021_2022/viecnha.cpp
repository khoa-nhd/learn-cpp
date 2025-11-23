#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 105

ll t, c, a[maxN];

void readData(){
    cin >> t >> c;
    for(int i = 0; i < c; ++i){
        cin >> a[i];
    }
}

ll viecNha(){
    ll res = 0;
    ll timeConsumed = 0;
    sort(a, a + c);
    for(int i = 0; i < c; ++i){
        if(a[i] + timeConsumed <= t){
            res += 1;
            timeConsumed += a[i];
        } else{
            break;
        }
    }
    return res;
}

int main(){
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();
    ll res;
    res = viecNha();
    cout << res;
    return 0;
}
