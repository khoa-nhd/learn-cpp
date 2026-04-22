#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll a[50];
vector<ll> cnt;
ll res = 0;

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void firstHalf(ll i, ll sum){
    if(i >= n/2) return;
    firstHalf(i+1, sum);
    sum += a[i];
    if(sum > m) return;
    cnt.push_back(sum);
    firstHalf(i+1, sum);
}

void secondHalf(ll i, ll sum){
    if(i >= n) return;
    secondHalf(i+1, sum);
    sum += a[i];
    if(sum > m) return;
//    cout << sum << " ";
    res += upper_bound(cnt.begin(), cnt.end(), m - sum) - cnt.begin();
    secondHalf(i+1, sum);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FESTIVAL.INP", "r", stdin);
    freopen("FESTIVAL.OUT", "w", stdout);
    readData();
    firstHalf(0, 0);
    cnt.push_back(0);
    sort(cnt.begin(), cnt.end());
//    for(ll x : cnt) cout << x << " ";
//    cout << "\n";
    res += cnt.size() - 1;
    secondHalf(n/2, 0);
//    cout << "\n";
    cout << res;
    return 0;
}
