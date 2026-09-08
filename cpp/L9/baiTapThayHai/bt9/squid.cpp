#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b;

int main(){
    freopen("SQUID.INP", "r", stdin);
    freopen("SQUID.OUT", "w", stdout);
    cin >> a >> b;
    vector<pair<ll, ll>> res;
    while(a != 0 && b != 0){
        ll k;
        if(abs(a) > abs(b)){
            k = -(a/b);
            ll bestK = k;
            ll minV = a + k * b;
            for(int i = -1; i <= 1; ++i){
                ll newK = k + i;
                ll v = a + newK * b;
                if(abs(v) < abs(minV)){
                    minV = v;
                    bestK = newK;
                }
            }
            res.push_back({1, bestK});
            a += bestK * b;
        } else{
            k = -(b/a);
            ll bestK = k;
            ll minV = b + k * a;
            for(int i = -1; i <= 1; ++i){
                ll newK = k + i;
                ll v = b + newK * a;
                if(abs(v) < abs(minV)){
                    minV = v;
                    bestK = newK;
                }
            }
            res.push_back({2, bestK});
            b += bestK * a;
        }
    }
    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); ++i){
        cout << res[i].first << " " << res[i].second << "\n";
    }
    return 0;
}
