#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll w, n, m;
ll a[maxN] = {}, b[maxN] = {};
ll maxA = LLONG_MIN, maxB = LLONG_MIN;

void readData(){
    cin >> w >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        maxA = max(maxA, a[i]);
    }
    for(int i = 0; i < m; ++i){
        cin >> b[i];
        maxB = max(maxB, b[i]);
    }
}

ll rowA(ll div){
    ll row = 1;
    ll current = 0;
    for(int i = 0; i < n; ++i){
        if(current + a[i] > div){
            row += 1;
            current = a[i] + 1;
        } else{
            current += a[i] + 1;
        }
    }
    return row;
}

ll rowB(ll div){
    ll row = 1;
    ll current = 0;
    div = w - div;
    for(int i = 0; i < m; ++i){
        if(current + b[i] > div){
            row += 1;
            current = b[i] + 1;
        } else{
            current += b[i] + 1;
        }
    }
    return row;
}

ll report(){
    ll minRow = LLONG_MAX;
    ll low = maxA, high = w - maxB;
    while(low <= high){
        ll half = (low + high) / 2;
        ll dongA = rowA(half);
        ll dongB = rowB(half);
        ll currRow = max(dongA, dongB);
        minRow = min(minRow, currRow);
        if(dongA > dongB){
            low = half + 1;
        } else{
            high = half - 1;
        }
    }
    return minRow;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("REPORT.INP", "r", stdin);
    freopen("REPORT.OUT", "w", stdout);
    readData();
    ll res = report();
    cout << res;
    return 0;
}
