#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll n, a[maxN];
ll pre[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

void sol(){
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i-1] + a[i];
    }
    ll res = 0;
    for(int i = 1; i < n; ++i){
        if(pre[i] == pre[n] - pre[i]){
            res = i;
            break;
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readData();
    sol();
    return 0;
}
