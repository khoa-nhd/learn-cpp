#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

pair<ll, ll> themMuongDua[maxN] = {};
ll n, m, k;
struct khach{
    ll t, d, a;
} khachs[maxN];

void readData(){
    cin >> n >> m >> k;
    for(int i = 0; i < k; ++i){
        cin >> khachs[i].t >> khachs[i].d >> khachs[i].a;
    }
}

void gruel(){
    ll i = 0, tg = 0;
    while(i < k && tg < maxN){
        tg += 1;
        n += themMuongDua[tg].first;
        m += themMuongDua[tg].second;
        if(khachs[i].t < tg) continue;
        while(khachs[i].t == tg){
            if(khachs[i].a == 0){
                if(n - 1 >= 0){
                    n -= 1;
                    cout << "YES" << "\n";
                    themMuongDua[khachs[i].t + khachs[i].d].first += 1;
                } else{
                    cout << "NO" << "\n";
                }
            } else{
                if(n - 1 >= 0 && m - 1 >= 0){
                    n -= 1;
                    m -= 1;
                    cout << "YES" << "\n";
                    themMuongDua[khachs[i].t + khachs[i].d].first += 1;
                    themMuongDua[khachs[i].t + khachs[i].d].second += 1;
                } else{
                    cout << "NO" << "\n";
                }
            }
            i += 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GRUEL.INP", "r", stdin);
    freopen("GRUEL.OUT", "w", stdout);
    readData();
    gruel();
    return 0;
}
