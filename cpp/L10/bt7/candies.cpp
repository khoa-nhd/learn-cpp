#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, m;
ll a[maxN] = {};
ll b[maxN];
ll sum = 0;

void readData(){
    cin >> m >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
}

void sol(){
    if(m >= sum){
        cout << 0;
        return;
    }
    sort(a, a + n, greater<int>());
    ll idx = 0;
    ll res = 0;
    while(m > 0 && idx < n){
        while(idx < n && a[idx + 1] == a[idx]) idx += 1;
        if(m > (idx + 1) * (a[idx] - a[idx + 1])){
            m -= (idx + 1) * (a[idx] - a[idx + 1]);
            a[idx] = a[idx + 1];
        } else{
            a[idx] -= (m / (idx + 1));
            m -= (m / (idx + 1)) * (idx + 1);
            for(int i = 0; i < m; ++i){
                b[i] = a[idx] - 1;
            }
            for(int i = m; i <= idx; ++i){
                b[i] = a[idx];
            }
            for(int i = idx + 1; i < n; ++i){
                b[i] = a[i];
            }
            break;
        }
    }
    for(int i = 0; i < n; ++i){
//        cout << b[i] << " ";
        res += b[i] * b[i];
    }
//    cout << "\n";
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CANDIES.INP", "r", stdin);
    freopen("CANDIES.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
