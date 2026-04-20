#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll reading(){
    ll maxx = LLONG_MIN, sum = 0;
    for(int i = 0; i < n; ++i){
        maxx = max(maxx, a[i]);
        sum += a[i];
    }
    if(maxx > sum / 2) return maxx * 2;
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("READING.INP", "r", stdin);
    freopen("READING.OUT", "w", stdout);
    readData();
    ll res;
    res = reading();
    cout << res;
    return 0;
}
