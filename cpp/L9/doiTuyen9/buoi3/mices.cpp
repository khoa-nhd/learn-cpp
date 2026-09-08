#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10005

ll t;
ll n, chuot[maxN], to[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> chuot[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> to[i];
    }
}

ll mices(){
    ll res = -1;
    sort(chuot, chuot + n);
    sort(to, to + n);
    for(int i = 0; i < n; ++i){
        res = max(res, abs(to[i] - chuot[i]));
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        ll res;
        res = mices();
        cout << res << "\n";
    }
    return 0;
}
