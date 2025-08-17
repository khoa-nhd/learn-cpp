// Tìm tổng và vị trí dãy con lớn nhất trong dãy

#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000

long long a[maxN] = {};
int n;

long long maxsubarray(){
    long long maxGlobal = 0;
    long long maxCurrent = 0;
    for(int i = 0; i < n; ++i){
        maxCurrent = max(a[i], a[i] + maxCurrent);
        if(i == 0){
            maxGlobal = maxCurrent;
        } else{
            maxGlobal = max(maxGlobal, maxCurrent);
        }
    }
    return maxGlobal;
}

int main(){
    long long m;
    m = maxsubarray();
    cout << m;
    return 0;
}

