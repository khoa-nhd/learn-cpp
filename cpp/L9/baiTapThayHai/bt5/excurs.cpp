#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, k, a[maxN] = {};
map<ll, ll> city;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void printCities(){
    for(auto x : city){
        cout << x.first << "," << x.second << "\n";
    }
    cout << "\n";
}

ll excurs(){
    for(int i = 0; i < k; ++i){
        city[a[i]] += 1;
    }
    ll maxCity = city.size();
    ll posStart = 0;
//    cout << city.size() << "\n";
//    printCities();
    for(int i = 0; i + k < n; ++i){
        if(city[a[i]] == 1) city.erase(a[i]);
        else city[a[i]] -= 1;
        city[a[i+k]] += 1;
//        cout << city.size() << "\n";
//        printCities();
        ll temp = city.size();
        if(maxCity < (ll)city.size()){
            maxCity = (ll)city.size();
            posStart = i + 1;
        }
    }
    return posStart + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("EXCURS.INP", "r", stdin);
    freopen("EXCURS.OUT", "w", stdout);
    readData();
    ll res;
    res = excurs();
    cout << res;
    return 0;
}
