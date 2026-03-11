#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

int uoc[maxN] = {};
int maxUoc[maxN] = {};
int k;

void sangUoc(){
    for(int i = 1; i * i < maxN; ++i){
        uoc[i*i] += 1;
        for(int j = i + 1; j * i < maxN; ++j){
            uoc[i*j] += 2;
        }
    }
    maxUoc[0] = 0;
    for(int i = 1; i < maxN; ++i){
        maxUoc[i] = max(maxUoc[i-1], uoc[i]);
    }
}

int an_pri(){
    if(k <= 0) cout << 0;
    for(int i = k; i >= 0; --i){
        if(uoc[i] >= maxUoc[i-1]) return i;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    sangUoc();
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> k;
        int res;
        res = an_pri();
        cout << res << "\n";
    }
    return 0;
}
