// hai cách đều đúng
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t;

ll bigMod(string &a, ll x){ // cách tự nghĩ
    ll res = 0;
    for(char b : a){
        res = (res * 10 + (b - '0')) % x;
    }
    return res;
}

string num86(ll n){
    for(int i = 1; i <= 200; ++i){
        vector<ll> nums(i, 6);
        for(int j = 0; j <= nums.size(); ++j){
            string num;
            for(int k = 0; k < nums.size(); ++k){
                char temp = nums[k] + '0';
                num.push_back(temp);
            }
//            cout << num << "\n";
            if(bigMod(num, n) == 0) return num;
            if(j < nums.size()) nums[j] = 8;
        }
    }
    return "-1";
}

//string num86(ll x){ // cách của thầy
//    ll a[205][205] = {};
//    for(int i = 1; i < 205; ++i){
//        a[i][0] = (a[i-1][0] * 10 + 8) % x;
//    }
//    for(int i = 0; i < 205; ++i){
//        for(int j = 1; j < 205; ++j){
//            a[i][j] = (a[i][j-1] * 10 + 6) % x;
//        }
//    }
//
//    pair<ll, ll> res;
//    res.first = 1000000;
//    res.second = 1000000;
//    for(int i = 0; i < 205; ++i){
//        for(int j = 0; j < 205; ++j){
//            if(a[i][j] == 0 && i + j != 0 && i + j <= 200){
////                cout << i + j << " ";
//                if(res.first + res.second > i + j){
//                    res.first = i;
//                    res.second = j;
//                }
//                if(res.first + res.second == i + j && res.first > i){
//                    res.first = i;
//                    res.second = j;
//                }
//            }
//        }
//    }
//    if(res.first == 1000000) return "-1";
//    string resStr;
//    for(int i = 0; i < res.first; ++i){
//        resStr.push_back('8');
//    }
//    for(int i = 0; i < res.second; ++i){
//        resStr.push_back('6');
//    }
//    return resStr;
//}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("NUM86.INP", "r", stdin);
    freopen("NUM86.OUT", "w", stdout);
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll n;
        cin >> n;
        string res;
        res = num86(n);
        cout << res << "\n";
    }
    return 0;
}
