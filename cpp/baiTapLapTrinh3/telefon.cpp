#include <bits/stdc++.h>
using namespace std;
#define maxN 300005
typedef long long ll;

ll n, d, a[maxN];

void readData(){
    cin >> n >> d;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll telefon(){
    ll result = 0;
    vector<ll> position;
    for(int i = 0;i < n; ++i){
        if(a[i] == 1){
            position.push_back(i);
        }
    }
    for(int i = 1; i < position.size(); ++i){
        if(position[i] - position[i-1] > d){
            result += (position[i] - position[i-1] - 1) / d;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TELEFON.INP", "r", stdin);
    freopen("TELEFON.OUT", "w", stdout);
    readData();
    ll m;
    m = telefon();
    cout << m;
    return 0;
}
