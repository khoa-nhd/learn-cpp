#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

pair<ll, ll> a[maxN];
ll n;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second < b.second;
}

void rep(){
    vector<ll> chon;
    sort(a, a + n, cmp);
    chon.push_back(a[0].second - 1);
    chon.push_back(a[0].second);
    for(int i = 1; i < n; ++i){
        ll trung = 0;
        if(chon[chon.size()-1] >= a[i].first){
            trung += 1;
        }
        if(chon[chon.size()-2] >= a[i].first){
            trung += 1;
        }
//        for(int j = chon.size() - 1; j >= 0; --j){
//            if(chon[j] >= a[i].first) trung += 1;
//            if(trung == 2) break;
//        }
        if(trung == 0){
            chon.push_back(a[i].second - 1);
            chon.push_back(a[i].second);
        } else if(trung == 1){
            chon.push_back(a[i].second);
        }
    }
    cout << chon.size();
    cout << "\n";
    for(ll x : chon){
        cout << x << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("REP.INP", "r", stdin);
    freopen("REP.OUT", "w", stdout);
    readData();
    rep();
    return 0;
}
