#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> num;
ll res = 0;
ll n, t, a[40];

void readData(){
    cin >> n >> t;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void gen(ll idx, ll v){
    if(idx == n / 2) return;
    num.push_back(v + a[idx]);
    gen(idx+1, v);
    gen(idx+1, v+a[idx]);
}

void cal(ll idx, ll v){
    if(idx == n) return;
    auto it = lower_bound(num.begin(), num.end(), t-(v+a[idx]));
    res += num.end() - it;
    cal(idx+1, v);
    cal(idx+1, v+a[idx]);
}

void exams(){
    num.push_back(0);
    gen(0, 0);
//    for(int i = 0; i < num.size(); ++i){
//        cout << num[i] << " ";
//    }
//    cout << "\n";
    sort(num.begin(), num.end());
    auto it = lower_bound(num.begin(), num.end(), t);
    res += num.end() - it;
    cal(n/2, 0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("EXAMS.INP", "r", stdin);
    freopen("EXAMS.OUT", "w", stdout);
    readData();
    exams();
    cout << res;
    return 0;
}
