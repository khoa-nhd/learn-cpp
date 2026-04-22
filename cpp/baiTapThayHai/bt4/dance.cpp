#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, k, h[maxN];
unordered_map<ll, ll> myMap;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }
}

ll dance(){
    ll result = 0;
    sort(h, h + n);
    for(int i = 0; i < n; ++i){
        ll need = h[i] - k;
        if(myMap.find(need) != myMap.end()){
            result += myMap[need];
        }
        myMap[h[i]] += 1;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DANCE.INP", "r", stdin);
    freopen("DANCE.OUT", "w", stdout);
    readData();
    ll result;
    result = dance();
    cout << result;
    return 0;
}
