#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[105][105];

struct doi{
    ll diem = 0;
    ll thang = 0;
    ll thua = -1;
    ll hoa = 0;
} team[105];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
}

void sol(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            team[i].diem += a[i][j];
            if(a[i][j] == 3) team[i].thang += 1;
            else if(a[i][j] == 1) team[i].hoa += 1;
            else team[i].thua += 1;
        }
    }

    ll maxx = LLONG_MIN;
    for(int i = 0; i < n; ++i){
        if(team[i].diem > maxx){
            maxx = team[i].diem;
        }
    }
    for(int i = 0; i < n; ++i){
        if(team[i].diem == maxx){
            cout << i + 1 << " ";
            cout << team[i].diem << " ";
            cout << team[i].thang << " ";
            cout << team[i].hoa << " ";
            cout << team[i].thua << " ";
            cout << "\n";
        }
    }

    bool coThangNhieuHonThua = false;
    for(int i = 0; i < n; ++i){
        if(team[i].thang > team[i].thua){
            cout << i+1 << " ";
            coThangNhieuHonThua = true;
        }
    }
    if(!coThangNhieuHonThua) cout << 0;
    cout << "\n";

    bool koThua = false;
    for(int i = 0; i < n; ++i){
        if(team[i].thua == 0){
            cout << i+1 << " ";
            koThua = true;
        }
    }
    if(!koThua) cout << 0;
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
