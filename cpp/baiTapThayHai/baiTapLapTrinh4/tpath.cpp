#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10000000
#define maxN2 2000

bool prime[maxN] = {};
ll n, m;
ll a[maxN2][maxN2] = {};
ll pathNums = 0, pathSum = 0;
//vector<ll> paths;
//ll checkVal = 5;

void sangNguyenTo(){
    for(int i = 2; i < maxN; ++i) prime[i] = true;
    ll loop = sqrt(maxN);
    for(int i = 2; i < loop; ++i){
        if(prime[i]){
            for(int j = i * i; j < maxN; j += i){
                prime[j] = false;
            }
        }
    }
}

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
}

void getCost(ll i, ll j){
    if(a[i][j] == 0) return;
    if(prime[a[i][j]]){
//        paths.push_back(a[i][j]);
        pathNums += 1;
        pathSum += a[i][j];
    }
    ll cost = a[i][j];
    for(int k = 1; k < 6; ++k){
        cost *= 10;
        cost += a[i][j+k];
        if(prime[cost]){
//            if(cost == checkVal){
//                ll here = 0;
//            }
            pathNums += 1;
            pathSum += cost;
//            paths.push_back(cost);
        }
    }

    cost = a[i][j];
    for(int k = 1; k < 6; ++k){
        cost *= 10;
        cost += a[i+k][j];
        if(prime[cost]){
//            if(cost == checkVal){
//                ll here = 0;
//            }
            pathNums += 1;
            pathSum += cost;
//            paths.push_back(cost);
        }
    }

    cost = a[i][j];
    for(int k = 1; k < 6; ++k){
        cost *= 10;
        cost += a[i+k][j+k];
        if(prime[cost]){
//            if(cost == checkVal){
//                ll here = 0;
//            }
            pathNums += 1;
            pathSum += cost;
//            paths.push_back(cost);
        }
    }
}

void tpath(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            getCost(i, j);
        }
    }
//    sort(paths.begin(), paths.end());
//    for(ll x : paths){
//        cout << x << " ";
//    }
//    cout << "\n";
    cout << pathNums << " " << pathSum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TPATH.INP", "r", stdin);
    freopen("TPATH.OUT", "w", stdout);
    sangNguyenTo();
    readData();
    tpath();
    return 0;
}
