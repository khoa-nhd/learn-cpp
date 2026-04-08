#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<int, int> um;
int n, a[5005];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

int element(){
    int res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i-1; j >= 0; --j){
            int need = a[i] - a[j];
            if(um[need] > 0){
                res += 1;
                break;
            }
        }
        for(int j = i; j >= 0; --j){
            um[a[i] + a[j]] += 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ELEMENT.INP", "r", stdin);
    freopen("ELEMENT.OUT", "w", stdout);
    readData();
    int res;
    res = element();
    cout << res;
    return 0;
}
