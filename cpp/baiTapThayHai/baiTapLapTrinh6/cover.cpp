#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a, b;
struct dgThang{
    ll l, r, idx;
} doan[maxN];

void readData(){
    cin >> n >> a >> b;
    for(int i = 0; i < n; ++i){
        cin >> doan[i].l >> doan[i].r;
        doan[i].idx = i;
    }
}

bool cmp(dgThang x, dgThang y){
    if(x.l == y.l) return x.r < y.r;
    return x.l < y.l;
}

bool coChe(ll canChe, ll s, ll e){
    return (s <= canChe && e >= canChe);
}

void cover(){
    if(a == b){
        for(int i = 0; i < n; ++i){
            if(coChe(a, doan[i].l, doan[i].r)){
                cout << 1 << "\n";
                cout << i+1;
                return;
            }
        }
        cout << -1;
        return;
    }
    sort(doan, doan + n, cmp);
    vector<ll> res;
    ll canChe = a;
    ll i = 0;
    while(canChe < b){
        ll maxche = -1;
        ll maxidx = -1;
        while(i < n && doan[i].l <= canChe){
            if(maxche < doan[i].r){
                maxche = doan[i].r;
                maxidx = i;
            }
            i += 1;
        }
        if(maxidx == -1 || maxche < canChe){
            cout << -1;
            return;
        }
        canChe = maxche;
        res.push_back(doan[maxidx].idx);
    }
    cout << res.size() << "\n";
    sort(res.begin(), res.end());
    for(int x : res){
        cout << x+1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("COVER.INP", "r", stdin);
    freopen("COVER.OUT", "w", stdout);
    readData();
    cover();
    return 0;
}
