#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll m, n;
pair<ll, ll> a[maxN], b[maxN];

void readData(){
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i].first;
        b[i].second = i;
    }
}

void asummin(){
    ll minn = LLONG_MAX, posA, posB;
    sort(a, a + m);
    sort(b, b + n);
    ll i, j;
    i = 0;
    j = n - 1;
    while(i < m && j >= 0){
        if(abs(a[i].first + b[j].first) < minn){
            minn = abs(a[i].first + b[j].first);
            posA = a[i].second;
            posB = b[j].second;
        }
        if(a[i].first + b[j].first > 0){
            j -= 1;
        } else if(a[i].first + b[j].first < 0){
            i += 1;
        } else{
            break;
        }
    }
    cout << posA + 1 << " " << posB + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ASUMMIN.INP", "r", stdin);
    freopen("ASUMMIN.OUT", "w", stdout);
    readData();
    asummin();
    return 0;
}
