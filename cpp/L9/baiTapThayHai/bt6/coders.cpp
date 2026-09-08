#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

pair<ll, ll> capDauNho[maxN] = {};
ll n, a[maxN] = {};
deque<ll> dq;
ll maxVal = LLONG_MIN;
ll tranDau = 0;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }
}

void tinhCapDauNho(){
    for(int i = 0; i < n; ++i){
        dq.push_back(a[i]);
    }

    ll giu = dq.front();
    dq.pop_front();
    while(giu != maxVal){
        tranDau += 1;
        ll temp = dq.front();
        dq.pop_front();
        capDauNho[tranDau] = {giu, temp};

        ll bo = min(giu, temp);
        giu = max(giu, temp);
        dq.push_back(bo);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CODERS.INP", "r", stdin);
    freopen("CODERS.OUT", "w", stdout);
    readData();
    tinhCapDauNho();
    ll truyVan;
    cin >> truyVan;
    for(int i = 0; i < truyVan; ++i){
        ll k;
        cin >> k;
        if(k <= tranDau){
            cout << capDauNho[k].first << " " << capDauNho[k].second << "\n";
        } else{
            k -= tranDau;
            cout << maxVal << " ";
            cout << dq[(k-1) % dq.size()] << "\n";
        }
    }
    return 0;
}
