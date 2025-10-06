#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll n, q, a[maxN] = {}, b[maxN] = {};
vector<ll> ranks;

void readData(){
    cin >> n >> q;
    for(int i = 1; i < n; ++i){
        cin >> a[i];
    }
}

void hrank(){
    ranks.push_back(1);
    for(int i = 1; i < n; ++i){
        ranks.insert(ranks.begin() + a[i], i+1);
    }
    for(int i = 0; i < ranks.size(); ++i){
        b[ranks[i]-1] = i+1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("HRANK.INP", "r", stdin);
    freopen("HRANK.OUT", "w", stdout);
    readData();
    hrank();
    for(int i = 0; i < q; ++i){
        ll truyvan;
        cin >> truyvan;
        cout << b[truyvan-1] << "\n";
    }
    return 0;
}
