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

int maxDiff(){
    int maxx = -1, current = 0;
    for(int i = 1; i < n; ++i){
        current = abs(a[i] - a[i-1]);
        if(current > maxx){
            maxx = current;
        }
    }
    return maxx;
}

int maxDiffNum(int maxDiff){
    int current = 0, result = 0;
    for(int i = 1; i < n; ++i){
        if(abs(a[i] - a[i-1]) == maxDiff){
            result += 2;
        }
    }
    return result;
}

int main(){
    freopen("MAXDIFF.INP", "r", stdin);
    freopen("MAXDIFF.OUT", "w", stdout);
    readData();
    int m;
    m = maxDiff();
    cout << m << " ";
    int num;
    num = maxDiffNum(m);
    cout << num;
    return 0;
}
