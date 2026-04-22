#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll input[25] = {}, t;
bool taken[25];
ll n;

//ll digitsum(ll a, ll b){ quay lui 2^n ko hiệu quả
//    ll result = LLONG_MAX;
//    for(int i = 0; i < n; ++i){
//        if(!taken[i]){
//            taken[i] = true;
//            ll temp = min(digitsum(a*10 + input[i], b), digitsum(a, b*10 + input[i]));
//            result = min(temp, result);
//            taken[i] = false;
//        }
//    }
//    if(result == LLONG_MAX) return a + b;
//    return result;
//}

ll digitsum(){
    ll a = 0, b = 0;
    sort(input, input + n);
    ll la0 = 0;
    for(int i = 0; i < n; ++i){
        if(input[i] != 0){
            a = input[i];
            input[i] = 0;
            b = input[i+1];
            input[i+1] = 0;
            if(i == 0) la0 = 0;
            else if(i == 1) la0 = 1;
            else la0 = 2;
            break;
        }
    }
    for(int i = 2; i < n; ++i){
        if(i % 2 == 0) a = a*10 + input[i];
        else b = b*10 + input[i];
    }
    return a + b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DIGITSUM.INP", "r", stdin);
    freopen("DIGITSUM.OUT", "w", stdout);
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n;
        for(int j = 0; j < n; ++j){
            cin >> input[j];
            taken[j] = false;
        }
        ll result;
        result = digitsum();
        cout << result << "\n";
    }
    return 0;
}
