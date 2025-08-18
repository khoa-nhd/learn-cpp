#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000

int a[maxN] = {}, n;

void readData(){
    cin >> n;
    int h, m;
    for(int i = 0; i < n; ++i){
        cin >> h >> m;
        a[i] = h*60 + m;
    }
}

int freecash(){
    if (n == 1){
        return 1;
    }
    if(n == 0){
        return 0;
    }
    int maxx = -1, current = 1;
    sort(a, a + n);
    for(int i = 1; i < n; ++i){
        if(a[i] != a[i - 1]){
            current = 1;
        } else if(a[i] == a[i-1]){
            current += 1;
        }
        if(current > maxx){
            maxx = current;
        }
    }
    return maxx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FREECASH.INP", "r", stdin);
    freopen("FREECASH.OUT", "w", stdout);
    readData();
    int m;
    m = freecash();
    cout << m;
    return 0;
}
