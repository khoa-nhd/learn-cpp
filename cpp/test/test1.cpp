#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000

long long a[maxN] = {};
int n;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

long long maxsubarray(){
    long long maxGlobal = -numeric_limits<long long>::infinity();
    long long maxCurrent = 0;
    for(int i = 0; i < n; ++i){
        maxCurrent = max(a[i], a[i] + maxCurrent);
        maxGlobal = max(maxGlobal, maxCurrent);
    }
    return maxGlobal;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    readData();
    long long m;
    m = maxsubarray();
    cout << m;
    return 0;
}
