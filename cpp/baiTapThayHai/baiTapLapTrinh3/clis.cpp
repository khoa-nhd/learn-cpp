#include <bits/stdc++.h>
using namespace std;
#define maxN 100005
typedef long long ll;

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void clis(){
    ll current = 1, maxx = -1;
    ll start, maxstart, start1, end1;
    for(int i = 0; i < n-1; ++i){
        if(current == 1){
            start = i;
        }
        if(a[i] <= a[i+1]) {
            current += 1;
        } else {
            current = 1;
        }
        if(current > maxx){
            maxx = current;
            maxstart = start;
        }
    }
    if(a[n-1] <= a[0]){
        current = 2;
        for(int i = 0; i < n; ++i){
            if(a[i] <= a[i+1]){
                current += 1;
            } else{
                end1 = i;
                break;
            }
        }
        for(int i = n-1; i >= 0; --i){
            if(a[i] >= a[i-1]){
                current += 1;
            } else{
                start1 = i;
                break;
            }
        }
        if(current > maxx){
            cout << start1+1 << " " << end1+1;
        } else{
            cout << maxstart+1 << " " << maxstart+maxx;
        }
    } else {
        cout << maxstart+1 << " " << maxstart+maxx;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CLIS.INP", "r", stdin);
    freopen("CLIS.OUT", "w", stdout);
    readData();
    clis();
    return 0;
}
