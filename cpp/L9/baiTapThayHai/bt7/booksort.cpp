#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, a[maxN];
ll dp[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll booksort(){
    for(int i = 0; i < n; ++i){
        if(a[i] != 1){
            dp[a[i]] = dp[a[i]-1];
        }
        dp[a[i]] += 1;
    }
    return n - dp[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BOOKSORT.INP", "r", stdin);
    freopen("BOOKSORT.OUT", "w", stdout);
    readData();
    ll res;
    res = booksort();
    cout << res;
    return 0;
}
