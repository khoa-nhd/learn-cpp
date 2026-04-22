#include <bits/stdc++.h>
using namespace std;
#define maxN 100005
typedef long long ll;

ll n, m, a[maxN], b[maxN];

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> b[i];
    }
}

ll searchsmaller(int d, int c, ll target){
    ll result = -1;
    while(d <= c){
        int half = (d+c)/2;
        if(a[half] < target){
            result = half;
            d = half + 1;
        } else {
            c = half - 1;
        }
    }
    return result;
}

ll pts(){
    ll result = 0;
    sort(a, a+n);
    sort(b, b+m);
    for(int i = 0; i < m; ++i){
        ll smallerpos = searchsmaller(0, n-1, b[i]);
        if(smallerpos != -1){
            result += smallerpos + 1;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PTS.INP", "r", stdin);
    freopen("PTS.OUT", "w", stdout);
    readData();
    ll m;
    m = pts();
    cout << m;
    return 0;
}
