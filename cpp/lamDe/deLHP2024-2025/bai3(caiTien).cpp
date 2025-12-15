#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, m, luongNuoc[maxN], bonChua[maxN];
ll preM[maxN] = {};
ll full[maxN] = {}, du[maxN] = {};
ll result[maxN] = {};

void readData(){
    cin >> n >> m;
    if(m > 200005) m = 2000005;
    for(int i = 0; i < n; ++i){
        cin >> luongNuoc[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> bonChua[i];
    }
}

ll greaterThanOrEqualTo(int d, int c, ll target){
    ll result = -1;
    while(d <= c){
        ll half = (d+c)/2;
        if(preM[half] >= target){
            result = half;
            c = half - 1;
        } else{
            d = half + 1;
        }
    }
    return result;
}

void locNuoc(){
    preM[0] = bonChua[0];
    for(int i = 1; i < m; ++i){
        preM[i] = preM[i-1] + bonChua[i];
    }

    for(int i = 0; i < n; ++i){
        ll pos = greaterThanOrEqualTo(0, m-1, luongNuoc[i]);
        if(pos != -1){
            full[pos-1] += 1;
            du[pos] += luongNuoc[i] - preM[pos-1];
        } else{
            du[0] += luongNuoc[i];
        }
    }

    for(int i = m-2; i >= 0; --i){
        full[i] += full[i+1];
    }

    for(int i = 0; i < m; ++i){
        result[i] = full[i]*bonChua[i] + du[i];
    }
    for(int i = 0; i < m; ++i){
        if(result[i] == 0) break;
        cout << result[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    locNuoc();
    return 0;
}
