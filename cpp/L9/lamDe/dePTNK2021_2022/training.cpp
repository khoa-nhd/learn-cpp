#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, m;
ll b[maxN];
struct vdv{
    ll base, idx;
    ll xg;
} a[maxN];
ll pre[maxN] = {};
ll res[maxN];

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i].base;
        a[i].idx = i;
    }
    for(int i = 1; i <= m; ++i){
        cin >> b[i];
    }
}

bool cmp(vdv x, vdv y){
    return x.base < y.base;
}

void sol(){
    sort(b+1, b + m+1);
    sort(a, a + n, cmp);
    for(int i = 1; i <= m; ++i){
        pre[i] = pre[i-1] + b[i];
    }
    for(int i = 0; i < n; ++i){
        ll j;
        if(i == 0) j = 0;
        else j = a[i-1].xg;
        ll gt = pre[j] + a[i].base;
        j += 1;
        while(j <= m){
            if(gt >= b[j]) gt += b[j];
            else break;
            j += 1;
        }
        a[i].xg = j-1;
        res[a[i].idx] = gt;
    }
    for(int i = 0; i < n; ++i){
        cout << res[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("TRAINING.INP", "r", stdin);
//    freopen("TRAINING.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
