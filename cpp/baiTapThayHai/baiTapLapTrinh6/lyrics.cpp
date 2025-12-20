#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n;
string a[1005];
ll maxK[1005] = {};

void readData(){
    cin >> n >> m;
    cin.ignore();
    for(int i = 0; i < n; ++i){
        getline(cin, a[i]);
    }
}

ll findMaxK(string &a, string &b){
    ll res = 0;
    ll i = a.size() - 1;
    ll j = b.size() - 1;
    while(i >= 0 && j >= 0){
        if(a[i] == b[j]){
            res += 1;
            i -= 1;
            j -= 1;
        } else{
            return res;
        }
    }
    return res;
}

ll lyrics(){
    for(int i = 0; i < n; ++i){
        if(i >= m){
            maxK[i] = min(maxK[i-m], findMaxK(a[i], a[i-m]));
        } else{
            maxK[i] = a[i].size();
        }
    }

    ll res = LLONG_MAX;
    for(int i = 0; i < n; ++i){
//        cout << a[i] << "\n";
        res = min(res, maxK[i]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LYRICS.INP", "r", stdin);
    freopen("LYRICS.OUT", "w", stdout);
    readData();
    ll res;
    res = lyrics();
    cout << res;
    return 0;
}
