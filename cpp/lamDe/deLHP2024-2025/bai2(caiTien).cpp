#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, a[maxN];
ll prefix[maxN] = {};
ll suffix[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

//ll dapnui(){
//    ll minenergy = LLONG_MAX;
//    ll energy = 0, prev = 0;
//    ll dinh;
//    for(int i = 1; i < n-1; ++i){
//        energy = 0;
//        prev = a[0];
//        for(int j = 1; j <= i; ++j){
//            if(a[j] <= prev){
//                energy += prev - a[j] + 1;
//                prev += 1;
//            } else{
//                prev = a[j];
//            }
//            if(j == i){
//                dinh = prev;
//            }
//        }
//        prev = a[n-1];
//        for(int j = n-2; j >= i; --j){
//            if(j != i){
//                if(a[j] <= prev){
//                    energy += prev - a[j] + 1;
//                    prev += 1;
//                } else{
//                    prev = a[j];
//                }
//            } else{
//                if(dinh <= prev){
//                    energy += prev - dinh + 1;
//                    prev += 1;
//                } else{
//                    prev = a[j];
//                }
//            }
//
//        }
//        minenergy = min(energy, minenergy);
//    }
//    return minenergy;
//}

ll dapnui(){
    prefix[0] = a[0];
    for(int i = 1; i < n; ++i){
        prefix[i] = max(a[i], prefix[i-1] + 1);
    }
    suffix[n-1] = a[n-1];
    for(int i = n-2; i >= 0; --i){
        suffix[i] = max(a[i], suffix[i+1] + 1);
    }

    ll highest = 0;
    ll minH = LLONG_MAX;
    for(int i = 1; i < n-1; ++i){
        if(minH > max(prefix[i], suffix[i])){
            minH = max(prefix[i], suffix[i]);
            highest = i;
        }
    }

    ll energy = 0, prev = 0;
    ll dinh;
    prev = a[0];
    for(int j = 1; j <= highest; ++j){
        if(a[j] <= prev){
            energy += prev - a[j] + 1;
            prev += 1;
        } else{
            prev = a[j];
        }
        if(j == highest){
            dinh = prev;
        }
    }
    prev = a[n-1];
    for(int j = n-2; j >= highest; --j){
        if(j != highest){
            if(a[j] <= prev){
                energy += prev - a[j] + 1;
                prev += 1;
            } else{
                prev = a[j];
            }
        } else{
            if(dinh <= prev){
                energy += prev - dinh + 1;
                prev += 1;
            } else{
                prev = a[j];
            }
        }
    }
    return energy;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    ll result;
    result = dapnui();
    cout << result;
    return 0;
}
