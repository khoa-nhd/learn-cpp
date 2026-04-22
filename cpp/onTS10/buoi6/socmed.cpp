#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
pair<string, string> a[105];
ll res[105] = {};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; ++i){
        string x, p;
        cin >> x >> p;
        a[i].first = x;
        a[i].second = p;
    }
    cin >> k;
    for(int i = 0; i < k; ++i){
        string x, p;
        cin >> x >> p;
        for(int j = 0; j < n; ++j){
            if(x == a[j].first && p == a[j].second) res[j] += 1;
        }
    }
    for(int i = 0; i < n; ++i) cout << res[i] << " ";
    return 0;
}
