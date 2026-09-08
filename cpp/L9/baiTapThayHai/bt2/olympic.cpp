#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll n, c;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n >> c;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

ll olympic(){
    ll result = 0;
    sort(a, a+n);
    for(int i = 0; i < n; ++i){
        if(c < a[i].first){
            break;
        } else{
            c += a[i].second;
            result += 1;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("OLYMPIC.INP", "r", stdin);
    freopen("OLYMPIC.OUT", "w", stdout);
    readData();
    ll m;
    m = olympic();
    cout << m;
    return 0;
}
