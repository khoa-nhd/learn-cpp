#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n;
pair<ll, ll> a[maxN] = {};
pair<ll, ll> res[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
}

void stat(){
    sort(a, a + n);
    for(int i = 0; i < n; ++i){
        if(i == n-1 || a[i].first != a[i + 1].first){
            ll j = i;
            while(j >= 0 && a[j].first == a[i].first){
                res[a[j].second].second = n - i - 1;
                j -= 1;
            }
        }
        if(i == 0 || a[i].first != a[i-1].first){
            ll j = i;
            while(j < n && a[j].first == a[i].first){
                res[a[j].second].first = i;
                j += 1;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        cout << res[i].first << " " << res[i].second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("STAT.INP", "r", stdin);
    freopen("STAT.OUT", "w", stdout);
    readData();
    stat();
    return 0;
}
