// Tìm tổng và vị trí dãy con lớn nhất trong dãy

#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000

long long a[maxN] = {-1, 3, -2, 5, 3, -3, 2, 2};
int n = 8;

void maxsubarray(){
    long long maxGlobal = 0;
    long long maxCurrent = 0;
    int start, endd;
    for(int i = 0; i < n; ++i){
        if(a[i] > a[i] + maxCurrent){
            start = i;
        }
        maxCurrent = max(a[i], a[i] + maxCurrent);
        if(i == 0){
            maxGlobal = maxCurrent;
            endd = i;
        } else{
            if(maxGlobal < maxCurrent){
                endd = i;
            }
            maxGlobal = max(maxGlobal, maxCurrent);
        }
    }
    cout << "Max sum: " << maxGlobal << "\n";
    cout << "Start: " << start << " End: " << endd;
}

int main(){
    maxsubarray();
    return 0;
}

