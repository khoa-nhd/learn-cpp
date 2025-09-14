#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll n, s, a[maxN];

void readData(){
    cin >> n >> s;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUMSEQ.INP", "r", stdin);
    freopen("SUMSEQ.OUT", "w", stdout);
    return 0;
}
