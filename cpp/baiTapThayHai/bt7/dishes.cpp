#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[10];
struct dish{
    vector<ll> v;
    ll lan;
};
queue<dish> q;
map<ll, int> exist;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    reverse(a, a + n);
}

void convert(){
    ll b[10];
    for(int i = 0; i < n; ++i){
        b[i] = a[i];
    }
    sort(b, b + n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i] == b[j]){
                a[i] = j;
            }
        }
    }
}

bool check(vector<ll> &cur){
    ll res = 0;
    ll mu = 1;
    for(int i = n-1; i >= 0; --i){
        res += cur[i] * mu;
        mu *= n;
    }
    if(exist[res] == 1) return false;
    exist[res] = 1;
    return true;
}

bool checkFinish(vector<ll> &cur){
    for(int i = 0; i < n; ++i){
        if(cur[i] != n-1-i) return false;
    }
    return true;
}

ll dishes(){
    dish temp;
    temp.lan = 0;
    for(int i = 0; i < n; ++i){
        temp.v.push_back(a[i]);
//        cout << a[i] << " ";
    }
//    cout << "\n";
    q.push(temp);
    check(temp.v);
    while(q.size() != 0){
        dish dia = q.front();
        q.pop();
//        for(int i = 0; i < n; ++i){
//            cout << dia.v[i] << " ";
//        }
//        cout << "\n";
        if(checkFinish(dia.v)){
            return dia.lan;
        }
        for(int i = 0; i < n-1; ++i){
            dish moi = dia;
            moi.lan += 1;
            reverse(moi.v.begin() + i, moi.v.end());
            if(check(moi.v)) q.push(moi);
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DISHES.INP", "r", stdin);
    freopen("DISHES.OUT", "w", stdout);
    readData();
    convert();
    ll res;
    res = dishes();
    cout << res;
    return 0;
}
