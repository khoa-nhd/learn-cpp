#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll n;
pair<ll, ll> a[maxN];

void readData(){
     cin >> n;
     for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
     }
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    ll x = (a.second - a.first) + (b.second - (a.first + b.first));
    ll y = (b.second - b.first) + (a.second - (a.first + b.first));
    return x > y;
}

ll reward(){
    sort(a, a + n, cmp);
    ll result = 0;
    ll timespent = 0;
    for(int i = 0; i < n; ++i){
        timespent += a[i].first;
        result += a[i].second - timespent;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("REWARD.INP", "r", stdin);
    freopen("REWARD.OUT", "w", stdout);
    readData();
    ll m = reward();
    cout << m;
    return 0;
}
