#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, m;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i].second >> a[i].first;
    }
}

ll boxes(){
    if(n == 0){
        return 0;
    } else if(n == 1){
        return a[0].second;
    }
    sort(a, a+n);
    ll result = 0, compare = a[0].first;
    for(int i = 0; i < n; ++i){
        if(a[i].first != compare){
            compare = a[i].first;
            result += a[i-1].second;
        }
    }
    result += a[n-1].second;
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BOXES.INP", "r", stdin);
    freopen("BOXES.OUT", "w", stdout);
    readData();
    ll result;
    result = boxes();
    cout << result;
    return 0;
}
