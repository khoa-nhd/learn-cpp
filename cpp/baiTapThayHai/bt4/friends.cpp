#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, b, s[maxN], a[maxN] = {};
unordered_map<ll, ll> myMap;

void readData(){
    cin >> n >> b;
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
}

ll friends() {
    ll result = 0;
    for(int i = 0; i < n; ++i){
        ll need = b - s[i];
        if(myMap.find(need) != myMap.end()){
            result += myMap[need];
        }
        myMap[s[i]] += 1;
    }
    return result;
}

/* sai vì s âm ll friends(){
    ll result = 0;
    for(int i = 0; i < n; ++i){
        if(b > s[i]){
            result += a[b - s[i]];
            a[s[i]] += 1;
        }
    }
    return result;
}*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FRIENDS.INP", "r", stdin);
    freopen("FRIENDS.OUT", "w", stdout);
    readData();
    ll result;
    result = friends();
    cout << result;
    return 0;
}
