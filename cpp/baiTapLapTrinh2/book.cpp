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

long long book(){
    long long result = 0;
    sort(a, a + n, greater<int>());
    for(int i = 0; i < n; ++i){
        if((i+1)%3 != 0){
            result += a[i];
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BOOK.INP", "r", stdin);
    freopen("BOOK.OUT", "w", stdout);
    readData();
    long long m;
    m = book();
    cout << m;
    return 0;
}
