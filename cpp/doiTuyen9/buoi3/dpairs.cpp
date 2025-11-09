#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[maxN] = {}, k;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll dpairs(){
    unordered_map<ll, ll> val;
    for(int i = 0; i < n; ++i){
        val[a[i]] += 1;
    }
    ll res = 0;
    for(int i = 0; i < n; ++i){
        ll need = a[i] - k;
        if(val.find(need) != val.end()){
            res += val[need];
        }
    }
    if(k == 0){
        res -= n;
    }
    return res;
}

ll dpairs2(){
    unordered_map<ll, ll> val;
    ll result = 0;
    sort(a, a + n);
    for(int i = 0; i < n; ++i){
        ll need = a[i] - k;
//        cout << a[i] << " " << need << " " << val[need] << "\n";
        if(val.find(need) != val.end()){
            result += val[need];
        }
        val[a[i]] += 1;
    }
    return result;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readData();
    ll res;
    if(k == 0){
        res = dpairs2();
    } else{
        res = dpairs();
    }
    cout << res;
    return 0;
}
