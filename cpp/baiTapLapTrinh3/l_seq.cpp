#include <bits/stdc++.h>
using namespace std;
#define maxN 1000001
typedef long long ll;

ll n, k, a[maxN];

void readData(){
    cin >> n >> k;
    for(int i = 0; i < k; ++i){
        cin >> a[i];
    }
}

ll lseq(){
    if(k == 1){
        return 1;
    }
    sort(a, a+k);
    bool found = false;
    ll current = 1, maxx = -1, maxEnd, start = a[1], maxStart;
    if(a[0] == 0){
        for(int i = 1; i < k-1; ++i){
            if(a[i+1] - a[i] == 1){
                current += 1;
            } else{
                current = 1;
                start = a[i+1];
            }
            if(current > maxx){
                maxx = current;
                maxEnd = a[i+1];
                maxStart = start;
            }
        }
    } else{
        for(int i = 0; i < k-1; ++i){
            if(a[i+1] - a[i] == 1){
                current += 1;
            } else{
                current = 1;
            }
            if(current > maxx){
                maxx = current;
            }
        }
        return maxx;
    }
    if(maxEnd < n || maxStart > 1){
        maxx += 1;
    }
    for(int i = 1; i < k-1; ++i){
        if(a[i+1] - a[i] == 2){
            current = 3;
            for(int j = i; j >= 2; --j){
                if(a[j]- a[j-1] == 1){
                    current += 1;
                } else{
                    break;
                }
            }
            for(int j = i + 1; j < k - 1; ++j){
                if(a[j+1] - a[j] == 1){
                    current += 1;
                } else{
                    break;
                }
            }
            if(current > maxx){
                maxx = current;
            }
        }
    }
    return maxx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("L_SEQ.inp", "r", stdin);
    freopen("L_SEQ.out", "w", stdout);
    readData();
    ll m;
    m = lseq();
    cout << m;
    return 0;
}
