#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll n, k, a[maxN];

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll subseq(){

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUBSEQ.INP", "r", stdin);
    freopen("SUBSEQ.OUT", "w", stdout);
    readData();
    ll m;
    m = subseq();
    cout << m;
    return 0;
}
