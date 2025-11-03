#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

pair<ll, ll> phamVi[maxN] = {};
ll n, m;
string s;

void readData(){
    cin >> n >> m;
    cin >> s;
}

void tinhPhamVi(){
    phamVi[1] = {1, 1};
    for(int i = 2; i <= n; ++i){
        phamVi[i].first = phamVi[i-1].second + 1;
        ll khoangCach = phamVi[i-1].second - phamVi[i-1].first + 1;
        phamVi[i].second = phamVi[i].first + khoangCach;
    }
    for(int i = n + 1; i <= 2*n - 1; ++i){
        phamVi[i].first = phamVi[i-1].second + 1;
        ll khoangCach = phamVi[i-1].second - phamVi[i-1].first - 1;
        phamVi[i].second = phamVi[i].first + khoangCach;
    }
}

ll jump(){
    ll res = 1;
    pair<ll, ll> toaDo = {1, 1};
    for(int i = 0; i < m; ++i){
        if(s[i] == 'U') toaDo.second -= 1;
        else if(s[i] == 'D') toaDo.second += 1;
        else if(s[i] == 'L') toaDo.first -= 1;
        else toaDo.first += 1;
        ll duongCheo = toaDo.first + toaDo.second - 1;
        if(duongCheo % 2 == 0){
            ll val = phamVi[duongCheo].first + toaDo.second - 1;
        } else{
            ll val = phamVi[duongCheo].first + (n - toaDo.second);
        }
        res += val;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();
    tinhPhamVi();
    ll res = jump();
    cout << res;
    return 0;
}
