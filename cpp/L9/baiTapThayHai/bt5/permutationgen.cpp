#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10005

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void output(){
    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }
}

bool checkNoSolution(){
    for(int i = 1; i < n; ++i){
        if(a[i] > a[i-1]) return false;
    }
    return true;
}

void permutationgen(ll start){
    ll maxprev = a[n-1];
    ll maxprevidx = n-1;
    ll minprev = LLONG_MAX;
    ll minprevidx;
    for(int i = n - 2; i >= 0; --i){
        if(a[i] < maxprev){
            for(int j = i + 1; j < n; ++j){
                if(a[j] < minprev && a[j] > a[i]){
                     minprev = a[j];
                     minprevidx = j;
                }
            }
            ll temp = a[i];
            a[i] = a[minprevidx];
            a[minprevidx] = temp;
            sort(a + i + 1, a + n);
            return;
        } else{
            maxprev = a[i];
            maxprevidx = i;
        }
    }
}

int main(){
    freopen("PERMUTATIONGEN.INP", "r", stdin);
    freopen("PERMUTATIONGEN.OUT", "w", stdout);
    readData();
    if(checkNoSolution()){
        cout << -1;
    } else{
        permutationgen(0);
        output();
    }
    return 0;
}

