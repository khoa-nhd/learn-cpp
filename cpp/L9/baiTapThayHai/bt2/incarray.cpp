#include <iostream>
#include <cstdio>
using namespace std;
#define maxN 1000000

int a[maxN], n;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

long long incarray(){
    long long result = 0;
    for(int i = 1; i < n; ++i){
        if(a[i] < a[i-1]){
            result += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("INCARRAY.INP", "r", stdin);
    freopen("INCARRAY.OUT", "w", stdout);
    readData();
    long long m;
    m = incarray();
    cout << m;
    return 0;
}
