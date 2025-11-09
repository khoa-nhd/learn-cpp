#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll namcham(){
    ll res = 1;
    ll prev = a[0];
    for(int i = 1; i < n; ++i){
        if(a[i] != prev){
            prev = a[i];
            res += 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readData();
    ll res;
    res = namcham();
    cout << res;
    return 0;
}
