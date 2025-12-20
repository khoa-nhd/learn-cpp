#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll k, l, m;
ll dp[maxN] = {};

void cointower(){
    for(int i = 1; i < maxN; ++i){
        int mot, hai, ba;
        mot = dp[i-1];
        if(i >= k) hai = dp[i-k];
        else hai = 1;
        if(i >= l) ba = dp[i-l];
        else ba = 1;

        if(mot == 0 || hai == 0 || ba == 0) dp[i] = 1;
        else dp[i] = 0;
    }

//    for(int i = 0; i < 15; ++i){
//        cout << dp[i] << "\n";
//    }
}

int main(){
    freopen("COINTOWER.INP", "r", stdin);
    freopen("COINTOWER.OUT", "w", stdout);
    cin >> k >> l >> m;
    cointower();
    for(int i = 0; i < m; ++i){
        ll temp;
        cin >> temp;
        if(dp[temp] == 1) cout << "A";
        else cout << "B";
    }
    return 0;
}
