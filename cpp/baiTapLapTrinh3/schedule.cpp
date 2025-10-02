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
    ll x = a.first + max(a.second, b.first + b.second);
    ll y = b.first + max(b.second, a.first + a.second);
    return x < y;
}

ll schedule(){
    sort(a, a + n, cmp);
    ll result = 0, longest = 0;
    for(int i = 0; i < n; ++i){
        result += a[i].first;
        longest = max(longest, result + a[i].second);
    }
    return longest;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SCHEDULE.INP", "r", stdin);
    freopen("SCHEDULE.OUT", "w", stdout);
    readData();
    ll m = schedule();
    cout << m;
    return 0;
}
