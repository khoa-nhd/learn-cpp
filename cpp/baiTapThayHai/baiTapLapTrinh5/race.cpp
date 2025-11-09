#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll m, n, a[maxN][maxN] = {};

void readData(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }
}

void race(){
    ll diem = LLONG_MIN;
    ll endd;
    vector<char> res;
    for(int j = 1; j <= m; ++j){
        for(int i = 1; i <= n; ++i){
            ll mot = a[i][j-1];
            ll hai = a[i-1][j-1];
            ll ba = a[i+1][j-1];
            a[i][j] += max(mot, max(hai, ba));
            diem = max(diem, a[i][j]);
        }
    }
//    for(int i = 1; i <= n; ++i){
//        for(int j = 1; j <= m; ++j){
//            cout << a[i][j] << " ";
//        }
//        cout << "\n";
//    }

    for(int i = 0; i < n; ++i){
        if(a[i][m] == diem){
            endd = i;
        }
    }
//    cout << endd << "\n";
    for(int j = m-1; j >= 1; --j){
        ll mot = a[endd][j];
        ll hai = a[endd-1][j];
        ll ba = a[endd+1][j];
        if(mot >= hai && mot >= ba){
            res.push_back('F');
        } else if(hai >= ba && hai >= mot){
            res.push_back('D');
            endd -= 1;
        } else{
            res.push_back('U');
            endd += 1;
        }
    }
    cout << endd << " " << diem << "\n";
    for(int i = res.size()-1; i >= 0; --i){
        cout << res[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("RACE.INP", "r", stdin);
    freopen("RACE.OUT", "w", stdout);
    readData();
    race();
    return 0;
}
