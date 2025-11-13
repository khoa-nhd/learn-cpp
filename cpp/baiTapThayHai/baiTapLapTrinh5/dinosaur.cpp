#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll n;
struct dino{
    ll idx, w, s;
} a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].w >> a[i].s;
        a[i].idx = i + 1;
    }
}

bool cmp(dino a, dino b){
    if(a.w != b.w) return a.w < b.w;
    return a.s > b.s;
}

void dinosaur(){
    sort(a, a + n, cmp);
    vector<ll> lis(n, 1);
    vector<ll> prev(n, -1);
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(a[i].w > a[j].w && a[i].s < a[j].s && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
        }
    }

    ll maxLen = 0, pos = -1;
    for(int i = 0; i < n; ++i){
        if(lis[i] > maxLen){
            maxLen = lis[i];
            pos = i;
        }
    }

    vector<ll> res;
    while(pos != -1){
        res.push_back(a[pos].idx);
        pos = prev[pos];
    }
    cout << res.size() << "\n";
    for(int i = res.size() - 1; i >= 0; --i){
        cout << res[i] << " ";
    }
}

int main(){
    freopen("DINOSAUR.INP", "r", stdin);
    freopen("DINOSAUR.OUT", "w", stdout);
    readData();
    dinosaur();
    return 0;
}
