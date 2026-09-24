#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n;
pair<ll, ll> a[maxN];
double pi = acos(-1);

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

void solve(){
    vector<double> v;
    for(int i = 0; i < n; ++i){
        double ps, t;
        t = atan2(a[i].first, a[i].second);
        t = t / pi * 180;
        if(t < 0) t += 360;
//        cout << a[i].first << " " << a[i].second << " " << (a[i].first < 0 && a[i].second > 0) << " ";
//        cout << t << "\n";
        v.push_back(t);
    }
    if(n == 1){
        cout << 0;
        return;
    }
    sort(v.begin(), v.end());
    double maxgap = 360 - (v[n-1] - v[0]);
    for(int i = 1; i < v.size(); ++i){
        maxgap = max(maxgap, v[i] - v[i-1]);
    }
    cout << fixed << setprecision(6);
    cout << 360 - maxgap;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("VIEWANGLE.INP", "r", stdin);
    freopen("VIEWANGLE.OUT", "w", stdout);
    readData();
    solve();
    return 0;
}
