#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, p[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
}

void killingseq(){
    ll half = n / 2;
    int i, j;
    sort(p, p + n);
    if(n % 2 == 0){
        i = n / 2 - 1;
        j = i + 1;
    } else{
        cout << p[n/2] << " ";
        i = n/2 - 1;
        j = n/2 + 1;
    }
    while(i >= 0 && j < n){
        cout << p[i] << " " << p[j] << " ";
        i -= 1;
        j += 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("KILLINGSEQ.INP", "r", stdin);
    freopen("KILLINGSEQ.OUT", "w", stdout);
    readData();
    killingseq();
    return 0;
}
