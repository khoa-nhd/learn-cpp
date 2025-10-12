#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
ll n = 9;
ll maxVal = 80; // cach 1
ll lastVal = 80; // cach 1
ll demcach1 = 0; // cach 1

//ll arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//ll n = 10;
//ll maxVal = 10; // cach 1
//ll lastVal = 10; // cach 1
//ll demcach1 = 0; // cach 1

ll findmaxCach1(int idx){
    ll maxx = 0;
    if(arr[idx] == maxVal || arr[idx] == lastVal){
        return 1;
    }
    for(int i = idx + 1; i < n; ++i){
        demcach1 += 1;
        if(arr[i] >= arr[idx]){
            maxx = max(maxx, findmaxCach1(i));
        }
    }
    return maxx + 1;
}

void cach1(){ // cách tự nghĩ ra O(n^3)
    ll lis = 0;
    for(int i = 0; i < n; ++i){
        lis = max(lis, findmaxCach1(i));
    }
    cout << "cach 1: dap an: " << lis << ", chay " << demcach1 << " lan" << "\n";
}

void cach2(){ // O(n^2)
    ll dem = 0, result = 0;
    vector<ll> lis(n, 1);
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            dem += 1;
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1){
                lis[i] =  lis[j] + 1;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        dem += 1;
        result = max(result, lis[i]);
    }
    cout << "cach 2: dap an: " << result << ", chay " << dem << " lan" << "\n";
}

void cach3(){ // O(n log n)
    ll dem = 0;
    vector<ll> ans;
    for(int i = 0; i < n; ++i){
        auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
        if(it == ans.end()){
            ans.push_back(arr[i]);
        } else{
            *it = arr[i];
        }
    }
    cout << "cach 3: dap an: " << ans.size() << ", chay n log n lan" << "\n";
}

int main(){
    cach1();
    cach2();
    cach3();
    return 0;
}
