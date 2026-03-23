#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll n, m;
char a[maxN][maxN] = {};
bool done[maxN][maxN];
ll res[5] = {};
int ci[4] = {-1, 0, 1, 0};
int cj[4] = {0, 1, 0, -1};

void readData(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
//            cout << a[i][j];
            if(a[i][j] == '#') done[i][j] = true;
        }
//        cout << "\n";
    }
}

bool checki(ll i, ll j){
    char c = a[i][j];
    if(c == a[i+1][j] && c == a[i+2][j] && c == a[i+3][j]){
        done[i][j] = true;
        done[i+1][j] = true;
        done[i+2][j] = true;
        done[i+3][j] = true;
        return true;
    }
    if(c == a[i][j+1] && c == a[i][j+2] && c == a[i][j+3]){
        done[i][j] = true;
        done[i][j+1] = true;
        done[i][j+2] = true;
        done[i][j+3] = true;
        return true;
    }
    return false;
}

bool checko(ll i, ll j){
    char c = a[i][j];
    if(c == a[i][j+1] && c == a[i+1][j] && c == a[i+1][j+1]){
        done[i][j] = true;
        done[i][j+1] = true;
        done[i+1][j] = true;
        done[i+1][j+1] = true;
        return true;
    }
    return false;
}

bool checkt(ll i, ll j){
    char c = a[i][j];
    if(c == a[i][j+1] && c == a[i][j+2] && c == a[i+1][j+1]){
        done[i][j] = true;
        done[i][j+1] = true;
        done[i][j+2] = true;
        done[i+1][j+1] = true;
        return true;
    }
    if(c == a[i+1][j] && c == a[i+2][j] && c == a[i+1][j-1]){
        done[i][j] = true;
        done[i+1][j] = true;
        done[i+2][j] = true;
        done[i+1][j-1] = true;
        return true;
    }
    if(c == a[i+1][j] && c == a[i+1][j-1] && c == a[i+1][j+1]){
        done[i][j] = true;
        done[i+1][j] = true;
        done[i+1][j-1] = true;
        done[i+1][j+1] = true;
        return true;
    }
    if(c == a[i+1][j] && c == a[i+1][j+1] && c == a[i+2][j]){
        done[i][j] = true;
        done[i+1][j] = true;
        done[i+1][j+1] = true;
        done[i+2][j] = true;
        return true;
    }
    return false;
}

bool checks(ll i, ll j){
    char c = a[i][j];
    if(c == a[i][j+1] && c == a[i+1][j] && c == a[i+1][j-1]){
        done[i][j] = true;
        done[i][j+1] = true;
        done[i+1][j] = true;
        done[i+1][j-1] = true;
        return true;
    }
    if(c == a[i+1][j] && c == a[i+1][j+1] && c == a[i+2][j+1]){
        done[i][j] = true;
        done[i+1][j] = true;
        done[i+1][j+1] = true;
        done[i+2][j+1] = true;
        return true;
    }
    return false;
}

bool checkl(ll i, ll j){
    char c = a[i][j];
    if(c == a[i+1][j] && c == a[i+2][j] && c == a[i+2][j+1]){
        done[i][j] = true;
        done[i+1][j] = true;
        done[i+2][j] = true;
        done[i+2][j+1] = true;
        return true;
    }
    if(c == a[i][j+1] && c == a[i][j+2] && c == a[i+1][j]){
        done[i][j] = true;
        done[i][j+1] = true;
        done[i][j+2] = true;
        done[i+1][j] = true;
        return true;
    }
    if(c == a[i][j+1] && c == a[i+1][j+1] && c == a[i+2][j+2]){
        done[i][j] = true;
        done[i][j+2] = true;
        done[i+1][j+1] = true;
        done[i+2][j+2] = true;
        return true;
    }
    if(c == a[i+1][j] && c == a[i+1][j-1] && c == a[i+1][j-2]){
        done[i][j] = true;
        done[i+1][j] = true;
        done[i+1][j-1] = true;
        done[i+1][j-2] = true;
        return true;
    }
    return false;
}

void check(ll i, ll j){
    if(checki(i, j)){
        res[0] += 1;
    } else if(checko(i, j)){
        res[1] += 1;
    } else if(checkt(i, j)){
        res[2] += 1;
    } else if(checks(i, j)){
        res[3] += 1;
    } else if(checkl(i, j)){
        res[4] += 1;
    }
}

void sol(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
//            cout << a[i][j];
            if(!done[i][j]){
                check(i, j);
            }
        }
//        cout << "\n";
    }
    for(int i = 0; i <= 4; ++i){
        cout << res[i] << " ";
    }
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
