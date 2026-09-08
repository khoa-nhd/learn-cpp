#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000

int a[maxN] = {}, m, n;

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

int buygifts(){
    int minDiff = -1, nowDiff = 0;
    sort(a, a+n);
    for(int i = m-1; i < n; ++i){
        nowDiff = a[i] - a[i - (m - 1)];
        if(nowDiff < minDiff || minDiff == -1){
            minDiff = nowDiff;
        }
    }
    return minDiff;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BUYGIFTS.INP", "r", stdin);
    freopen("BUYGIFTS.OUT", "w", stdout);
    readData();
    int m;
    m = buygifts();
    cout << m;
    return 0;
}
