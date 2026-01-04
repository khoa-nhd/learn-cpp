#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10000005

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
    freopen("IMPERFECT.INP", "r", stdin);
    freopen("IMPERFECT.OUT", "w", stdout);
    sangTongUoc();
    cin >> l >> r;
    ll res = 0;
    for(int i = l; i <= r; ++i){
        res += abs(i - (tongUoc[i] - i));
    }
    cout << res;
    return 0;
}
