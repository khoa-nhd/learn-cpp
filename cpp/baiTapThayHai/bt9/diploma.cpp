#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN];
ll sum = 0;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
}

bool check(){
    deque<ll> dq;
    ll minVal[maxN];
}

ll diploma(){
    ll d = 1, c = n;
    while(d <= c){
        ll half = (d + c) / 2;

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DIPLOMA.INP", "r", stdin);
    freopen("DIPLOMA.OUT", "w", stdout);
    readData();
    ll res;
    res = diploma();
    cout << res;
    return 0;
}
