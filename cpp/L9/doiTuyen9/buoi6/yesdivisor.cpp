#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10000005

int n, k;
int uoc[maxN] = {};

void sangUoc(){
    for(int i = 1; i * i < maxN; ++i){
        uoc[i*i] += 1;
        for(int j = i + 1; j * i < maxN; ++j){
            uoc[i*j] += 2;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    sangUoc();
    int res = 0;
    for(int i = 1; i <= n; ++i){
        if(uoc[i] <= k) res += 1;
    }
    cout << res;
    return 0;
}
