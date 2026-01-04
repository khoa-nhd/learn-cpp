#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll l, r;
ll tongUoc[maxN] = {};

void sangTongUoc(){
    ll loop = sqrt(maxN);
    for(int i = 1; i <= loop; ++i){
        tongUoc[i*i] += i;
        for(int j = i + 1; j <= (maxN - 1)/i; ++j){
            tongUoc[i*j] += i + j;
        }
    }
}

int main(){
    freopen("PP.INP", "r", stdin);
    freopen("PP.OUT", "w", stdout);
    sangTongUoc();
    cin >> l >> r;
    ll res = 0;
    for(int i = l; i <= r; ++i){
        if(tongUoc[i] - i > i) res += 1;
    }
    cout << res;
    return 0;
}
