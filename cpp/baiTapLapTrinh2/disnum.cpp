#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000

int a[maxN] = {}, n;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

int disnum(){
    int result = 1;
    sort(a, a+n);
    for(int i = 1; i < n; ++i){
        if(a[i] != a[i-1]){
            result += 1;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DISNUM.INP", "r", stdin);
    freopen("DISNUM.OUT", "w", stdout);
    readData();
    int m;
    m = disnum();
    cout << m;
    return 0;
}
