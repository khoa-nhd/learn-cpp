#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n, k;
vector<ll> a, b;

void readData(){
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> b[i];
    }
}

ll searchh(int d, int c, ll target){
    while(d <= c){
        int half = (d+c)/2;
        if(b[half] >= target - k && b[half] <= target + k){
            return half;
        }
        if(target < b[half]){
            c = half - 1;
        } else{
            d = half + 1;
        }
    }
    return -1;
}

ll apartments(){
    ll result = 0;
    sort(b.begin(), b.end());
    for(int i = 0; i < n; ++i){
        int cuoi = (int)b.size() - 1;
        ll findd = searchh(0, cuoi, a[i]);
        if(findd != -1){
            result += 1;
            b.erase(b.begin() + findd);
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("APARTMENTS.INP", "r", stdin);
    freopen("APARTMENTS.OUT", "w", stdout);
    readData();
    ll m;
    m = apartments();
    cout << m;
    return 0;
}
