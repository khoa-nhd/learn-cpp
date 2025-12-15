#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, m, a[maxN] = {}, b[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
//        cout << a[i] << "\n";
    }
//    cout << "\n";
    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> b[i];
//        cout << b[i] << "\n";
    }
}

ll sol(){

    ll idxA = 0;
    ll idxB = m-1;
//    for (int i = 1; i < n; i++) {
//        if (a[i] >= a[i - 1])
//            idxA = i;
//        else break;
//    }
//
//    for (int i = m - 2; i >= 0; i--) {
//        if (b[i] <= b[i + 1])
//            idxB = i;
//        else break;
//    }

    while (idxA < n - 1 && a[idxA] <= a[idxA + 1]) idxA++;
    while (idxB > 0 && b[idxB] >= b[idxB - 1]) idxB--;

    ll res = 0;
    for(int i = 0; i <= idxA; ++i){
        while(idxB < m && b[idxB] < a[i]) idxB += 1;
        if (idxB >= m) break;
        res = max(res, (m - idxB) + i + 1);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MARBLE.INP", "r", stdin);
    freopen("MARBLE.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
