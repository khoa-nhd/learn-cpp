#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, a[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll chair(){
    ll res = 0;
    sort(a, a + n);
    ll noi = n - 1;
    ll i = 0;
    while(noi > 0){
        if(a[i] == 1){
            res += 1;
            i += 1;
            noi -= 2;
        } else{
            res += 1;
            noi -= 1;
            a[i] -= 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readData();
    ll res;
    res = chair();
    cout << res;
    return 0;
}
