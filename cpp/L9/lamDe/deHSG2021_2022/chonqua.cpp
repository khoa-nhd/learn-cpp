#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll d, r, k;
ll a[maxN][maxN] = {};
ll prefix[maxN][maxN] = {};
pair<ll, ll> tl = {2, 2};
pair<ll, ll> tr = {2, 2+k-3};
pair<ll, ll> bl = {2+k-3, 2};
pair<ll, ll> br = {2+k-3, 2+k-3};

void readData(){
    cin >> d >> r >> k;
    for(int i = 1; i <= d; ++i){
        for(int j = 1; j <= r; ++j){
            char temp;
            cin >> temp;
            if(temp == '*') a[i][j] = 1;
//            cout << a[i][j] << " ";
        }
//        cout << "\n";
    }
//    cout << "\n";
}

void prefixSum(){
    for(int i = 1; i <= d; ++i){
        for(int j = 1; j <= r; ++j){
            prefix[i][j] = a[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
//            cout << prefix[i][j] << " ";
        }
//        cout << "\n";
    }
//    cout << "\n";
}

void tinhIndex(){
//    cout << "\n";
    tl = {br.first - (k-3), br.second - (k-3)};
    tr = {br.first - (k-3), br.second};
    bl = {br.first, br.second  - (k-3)};
//    cout << tl.first << " " << tl.second << "\n";
//    cout << tr.first << " " << tr.second << "\n";
//    cout << bl.first << " " << bl.second << "\n";
//    cout << br.first << " " << br.second << "\n";
}

ll chonQua(){
    if(k <= 2) return 0;

    ll maxSum = -1;
    for(int i = 2+k-3; i < d; ++i){
        for(int j = 2+k-3; j < r; ++j){
            br = {i, j};
            tinhIndex();
            ll sum;
            sum = prefix[br.first][br.second] - prefix[tr.first-1][tr.second] - prefix[bl.first][bl.second-1] + prefix[tl.first-1][tl.second-1];
//            if(sum > maxSum) cout << br.first << " " << br.second << "\n";
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();
    prefixSum();
    ll res;
    res = chonQua();
    cout << res;
    return 0;
}
