#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a;

ll doiSang0(){
    vector<int> arr;
    ll result = 0;
    for(char x : a){
        arr.push_back(x - '0');
    }
    for(int i = 0; i < arr.size(); ++i){
        if(arr[i] != 0){
            if(arr.size() - i < 4){
                return -1;
            } else{
                result += 1;
                for(int j = 0; j < 4; ++j){
                    if(arr[i+j] == 0){
                        arr[i+j] = 1;
                    } else{
                        arr[i+j] = 0;
                    }
                }
            }
        }
    }
    return result;
}

ll doiSang1(){
    vector<int> arr;
    ll result = 0;
    for(char x : a){
        arr.push_back(x - '0');
    }
    for(int i = 0; i < arr.size(); ++i){
        ll temp = arr[i];
        if(arr[i] != 1){
            if(arr.size() - i < 4){
                return -1;
            } else{
                result += 1;
                for(int j = 0; j < 4; ++j){
                    if(arr[i+j] == 0){
                        arr[i+j] = 1;
                    } else{
                        arr[i+j] = 0;
                    }
                }
            }
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BITSTR.INP", "r", stdin);
    freopen("BITSTR.OUT", "w", stdout);
    cin >> a;
    ll soLanCan0, soLanCan1;
    soLanCan0 = doiSang0();
    soLanCan1 = doiSang1();
    if(soLanCan0 == -1){
        cout << soLanCan1;
    } else if(soLanCan1 == -1){
        cout << soLanCan0;
    } else{
        cout << min(soLanCan0, soLanCan1);
    }
    return 0;
}
