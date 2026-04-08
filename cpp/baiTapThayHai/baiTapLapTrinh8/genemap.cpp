#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, k;
string a[maxN];
unordered_map<string, ll> bangK;
unordered_map<string, ll> lonHonK;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll genemap(){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        if(a[i].size() < k) continue;
        string pre = a[i].substr(0, k);
        string suf = a[i].substr(a[i].size() - k, k);
        pre += suf;

        if(a[i].size() > k){
            string pre2 = a[i].substr(0, k + 1);
            string suf2 = a[i].substr(a[i].size() - k - 1, k+1);
            pre2 += suf2;

            res += bangK[pre] - lonHonK[pre2];
            lonHonK[pre2] += 1;
        } else{
            res += bangK[pre];
        }
        bangK[pre] += 1;
    }
    res %= 1000000007;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GENEMAP.INP", "r", stdin);
    freopen("GENEMAP.OUT", "w", stdout);
    readData();
    ll res;
    res = genemap();
    cout << res;
    return 0;
}
