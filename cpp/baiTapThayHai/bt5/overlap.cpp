#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll n;
struct input{
    ll s, e, idx;
} a[maxN];
ll dp[maxN] = {}, pre[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].s;
        cin >> a[i].e;
        a[i].idx = i;
    }
}

bool cmp(input a, input b){
    if(a.e == b.e) return a.s < b.s;
    return a.e < b.e;
}

void overlap(){
    sort(a, a + n, cmp);

    for(int i = 0; i < maxN; ++i){
        pre[i] = -1;
        dp[i] = 1;
    }

    for(int i = 0; i < n; ++i){
        for(int j = i - 1; j >= 0; --j){
            if(a[i].s == a[j].e){
                if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
    }

    ll maxLen = -1;
    ll pos = -1;
    for(int i = 0; i < n; ++i){
//        cout << dp[i] << " ";
        if(maxLen < dp[i]){
            maxLen = dp[i];
            pos = i;
        }
    }
//    cout << "\n";

//    for(int i = 0; i < n; ++i){
//        cout << pre[i] << " ";
//    }
//    cout << "\n";

    cout << maxLen << "\n";
    vector<ll> res;
    while(pre[pos] != -1){
        res.push_back(pos);
        pos = pre[pos];
    }
    res.push_back(pos);

    for(int i = res.size() - 1; i >= 0; --i){
        cout << a[res[i]].idx + 1 << "\n";
    }
}

int main(){
    freopen("OVERLAP.INP", "r", stdin);
    freopen("OVERLAP.OUT", "w", stdout);
    readData();
    overlap();
    return 0;
}
