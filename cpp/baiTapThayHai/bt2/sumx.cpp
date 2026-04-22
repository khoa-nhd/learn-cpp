#include <bits/stdc++.h>
using namespace std;
#define maxN 100005
typedef long long ll;

ll a[maxN], n, x;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cin >> x;
}

ll sumx() {
    ll result = 0;
    unordered_map<ll, ll> myMap;
    for(int i = 0; i < n; ++i){
        ll need = x - a[i];
        if(myMap.find(need) != myMap.end()){
            result += myMap[need];
        }
        myMap[a[i]] += 1;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUMX.INP", "r", stdin);
    freopen("SUMX.OUT", "w", stdout);
    readData();
    ll m;
    m = sumx();
    cout << m;
    return 0;
}
