#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

ll ocd(bool ld){
    vector<ll> v;
    ll x = n;
    while(x > 0){
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    for(int i = 1; i < v.size(); ++i){
        if(v[i] == v[i-1]){
            v[i] += 1;
            if(v[i] == 10){
                v[i] = 0;
                for(int j = i-1; j >= 0; --j){
                    if(v[j] == 9 && j == 0){
                        ll res = 0;
                        for(int k = 0; k < v.size() + 1; ++k){
                            res *= 10;
                            res += (k+1) % 2;
                        }
                        return res;
                    }
                    if(v[j] == 9) v[j] = 0;
                    else{
                        v[j] += 1;
                        break;
                    }
                }
            }
            n = 0;
            for(int i = 0; i < v.size(); ++i){
                n *= 10;
                n += v[i];
            }
            return ocd(false);
        }
    }
    if(ld){
        n += 1;
        return ocd(false);
    }
    return n;
}

int main(){
    freopen("OCD.INP", "r", stdin);
    freopen("OCD.OUT", "w", stdout);
    cin >> n;
    ll res;
    res = ocd(true);
    cout << res;
    return 0;
}

