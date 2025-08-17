// Tìm tổng và vị trí dãy con lớn nhất trong dãy

#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000

long long a[] = {-1, 3, -2, 5, 3, -3, 2, 2, -20, 5, 3};
int n = sizeof(a) / sizeof(a[0]);

void maxsubarray(){
    long long maxGlobal = 0;
    long long maxCurrent = 0;
    int start, endd, startGlobal;
    for(int i = 0; i < n; ++i){
        if(a[i] > a[i] + maxCurrent){
            start = i;
        }
        maxCurrent = max(a[i], a[i] + maxCurrent);
        if(i == 0){
            maxGlobal = maxCurrent;
            endd = i;
            startGlobal = start;
        } else{
            if(maxGlobal < maxCurrent){
                endd = i;
                startGlobal = start;
            }
            maxGlobal = max(maxGlobal, maxCurrent);
        }
    }
    cout << "Max sum: " << maxGlobal << "\n";
    cout << "Start: " << startGlobal << " End: " << endd;
}

int main(){
    cout << n << "\n";
    cout << sizeof(a) << "\n";
    cout << sizeof(a[0]) << "\n";
    cout << sizeof(n) << "\n";
    maxsubarray();
    return 0;
}

