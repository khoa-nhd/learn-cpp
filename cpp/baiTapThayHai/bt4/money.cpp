#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100000

ll n, g, s, k;
struct tien{
    ll p, q, r;
} a[maxN];

void readData(){
    ll p, q, r;
    cin >> g >> s >> k;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].p >> a[i].q >> a[i].r;
    }
}

bool tru(tien a){
    if(k < a.r){
        k += 29;
        s -= 1;
    }
    k -= a.r;
    if(s < a.q){
        s += 17;
        g -= 1;
    }
    s -= a.q;
    if(g < a.p) return false;
    g -= a.p;
    return true;
}

void money(){
    for(int i = 0; i < n; ++i){
        if(!tru(a[i])){
            cout << -1;
            return;
        }
    }
    cout << g << " " << s << " " << k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MONEY.INP", "r", stdin);
    freopen("MONEY.OUT", "w", stdout);
    readData();
    money();
    return 0;
}
