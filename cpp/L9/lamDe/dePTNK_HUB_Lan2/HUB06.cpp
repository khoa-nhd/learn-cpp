#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int mun;
int maxadn = 0;
vector<int> res;

void upmax(vector<int> &v){
    set<vector<int>> s;
    for(int i = 1; i <= mun; i *= 2){
        for(int j = 0; j+i <= mun; j += i){
            vector<int> t;
            for(int k = 0; k < i; ++k){
                t.push_back(v[k+j]);
            }
            s.insert(t);
        }
    }
//    for(int x : v) cout << x;
//    cout << "\n";
//    for(vector<int> vv : s){
//        for(int x : vv) cout << x;
//        cout << " ";
//    }
//    cout << "\n";
    if(s.size() > maxadn){
        maxadn = s.size();
        res = v;
    }
}

void sub1(int idx, vector<int> v){
    if(idx >= mun){
        upmax(v);
        return;
    }
    v.push_back(0);
    sub1(idx+1, v);
    v.pop_back();
    v.push_back(1);
    sub1(idx+1, v);
}

void sub3(){
    ll k = 0;
    for(int i = 0; i < n; ++i){
        if(i <= (1 << (n-i))) k = i;
    }
    ll dodaichuoi = (1 << (n-k));
    ll sochuoi = (1 << k);
    for(int i = 0; i < sochuoi; ++i){
        for(int j = dodaichuoi - 1; j >= 0; --j){
            cout << ((i >> j) & 1)
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("HUB06.INP", "r", stdin);
    freopen("HUB06.OUT", "w", stdout);
    cin >> n;
    mun = 1 << n;
    sub3()
    return 0;
}
