#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 2005

ll n, a[maxN], b[maxN], c[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        c[i] = a[i];
    }
}

void sol(){
    sort(c, c + n);
    for(int i = 0; i < n; ++i){
        if(c[i] > b[i]){
            cout << -1 << "\n";
            return;
        }
    }
    bool used[maxN] = {};
    for(int i = 0; i < n; ++i){
        if(a[i] <= b[i]) a[i] = i;
        else{
            for(int j = i+1; j < n; ++j){
                if(a[i] < b[j] && !used[j]){
                    a[i] = j;
                    used[j] = true;
                    break;
                }
                if(j == n - 1){
                    cout << -1 << "\n";
                    return;
                }
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(a[j] < a[i]) res += 1;
        }
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        sol();
    }
    return 0;
}
