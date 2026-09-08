#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, k;
ll a[maxN], m[maxN];
ll tongdocao = 0;
ll sawHeight[maxN] = {};
ll maxHeight = -1;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        tongdocao += a[i];
        maxHeight = max(a[i], maxHeight);
    }
    for(int i = 0; i < k; ++i){
        cin >> m[i];
    }
}

ll mysearch(int d, int c, ll target){
    ll result = 0;
    while(d <= c){
        ll half = (d+c)/2;
        if(a[half] < target){
            result = half + 1;
            d = half + 1;
        } else{
            c = half - 1;
        }
    }
    return result;
}

ll mysearch2(int d, int c, ll target){
    ll result = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(sawHeight[half] >= target){
            result = half;
            d = half + 1;
        } else{
            c = half - 1;
        }
    }
    return result;
}

void saw(){
    sort(a, a + n);
    sawHeight[0] = tongdocao;
    for(int i = 1; i < maxHeight; ++i){
        sawHeight[i] = sawHeight[i-1] - n;
        sawHeight[i] += mysearch(0, n-1, i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SAW.INP", "r", stdin);
    freopen("SAW.OUT", "w", stdout);
    readData();
    saw();
    for(int i = 0; i < k; ++i){
        cout << mysearch2(0, maxHeight, m[i]) << " ";
    }
    return 0;
}
