#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000

int a[maxN], n;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

int maxFreq(){
    if (n == 1){
        return a[0];
    }
    if(n == 0){
        return 0;
    }
    int maxx = -1, current = 1, maxVal;
    sort(a, a + n);
    for(int i = 1; i < n; ++i){
        if(a[i] != a[i - 1]){
            current = 1;
        } else if(a[i] == a[i-1]){
            current += 1;
        }
        if(current > maxx){
            maxx = current;
            maxVal = a[i];
        }
    }
    if(maxx == 1){
        return a[0];
    }
    return maxVal;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MAXFREQ.INP", "r", stdin);
    freopen("MAXFREQ.OUT", "w", stdout);
    readData();
    int m;
    m = maxFreq();
    cout << m;
    return 0;
}
