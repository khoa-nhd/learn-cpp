#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n;
pair<ll, ll> a[maxN];
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
    res[a[0].second].first = 0;
    for(int i = 0; i < n; ++i){
        if(i != 0 && a[i].first != a[i-1].first){
            res[a[i].second].first = i;
        } else{
            res[a[i].second].first = res[a[i-1].second].first;
        }
        if(a[i].first != a[i+1].first){
            for(int j = i; j >= 0; --j){
                if(a[j].first != a[i].first) break;
                res[a[j].second].second = n - i - 1;
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
