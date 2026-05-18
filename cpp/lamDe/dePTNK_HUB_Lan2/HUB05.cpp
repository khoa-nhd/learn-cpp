#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int a[100];

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

vector<int> subvec(int i, int len){
    vector<int> res;
    for(int j = 0; j < len; ++j){
        res.push_back(a[i+j]);
    }
    return res;
}

bool check(int l, int r){
    if((r - l + 1) % k != 0) return false;
    ll len = (r - l + 1) / k;
    vector<int> v1, v2;
    for(int i = l; i + len + len - 1 <= r; ++i){
        v1 = subvec(i, len);
        v2 = subvec(i+len, len);
        if(v1 != v2) return false;
    }
    cout << len << "\n";
    for(int x : v1) cout << x << " ";
    return true;
}

void sol(){
    if(k == 1){
        cout << 1 << "\n";
        cout << a[0];
        return;
    }
    for(int i = 0; i < n; ++i){
        for(int j = n - 1; j >= 0; --j){
            if(i < j){
                if(check(i, j)) return;
            }
        }
    }
    cout << -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("HUB05.INP", "r", stdin);
    freopen("HUB05.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
