#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll n, m;
ll a[maxN], b[maxN];
pair<ll, ll> ab[maxN];

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
}

void mergeArray(){
    for(int i = 0; i < n; ++i){
        ab[i] = {b[i], a[i]};
    }
}

ll coins(){
    ll result = m;
    sort(ab, ab + n);
    for(int i = 0; i < n; ++i){
        if(result >= ab[i].first - ab[i].second){
            result += ab[i].second;
        } else{
            break;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("COINS.INP", "r", stdin);
    freopen("COINS.OUT", "w", stdout);
    readData();
    mergeArray();
    ll m;
    m = coins();
    cout << m;
    return 0;
}
