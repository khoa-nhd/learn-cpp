#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

int uoc[maxN] = {};
ll res[maxN] = {};
int k;

void sangUoc(){
    for(int i = 1; i * i < maxN; ++i){
        uoc[i*i] += 1;
        for(int j = i + 1; j * i < maxN; ++j){
            uoc[i*j] += 2;
        }
    }
}

void an_pri(){
    ll maxx = 0;
    ll antiprime = 1;
    for(int i = 1; i < maxN; ++i){
        if(uoc[i] > maxx){
            maxx = uoc[i];
            antiprime = i;
        }
        res[i] = antiprime;
    }
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
        cout << res[i] << "\n";
    }
    return 0;
}
