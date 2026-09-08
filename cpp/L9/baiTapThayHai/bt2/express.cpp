#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000

int a[maxN], n, k;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

long long express(){
    long long result = 0;
    sort(a+1, a+n, greater<int>());
    for(int i = 0; i <= k; ++i){
        result += a[i];
    }
    for(int i = k+1; i < n; ++i){
        result -= a[i];
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("EXPRESS.INP", "r", stdin);
    freopen("EXPRESS.OUT", "w", stdout);
    readData();
    long long m;
    m = express();
    cout << m;
    return 0;
}
