#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a;

void readData(){
    ll temp;
    while(cin >> temp){
        a.push_back(temp);
    }
}

ll gifts(){
    ll result = 0;
    sort(a.begin(), a.end());
    ll n = a.size();
    ll left, right;
    for(int i = 0; i < n; ++i){
        right = n-1;
        left = 0;
        while(left < right){
            if(left == i){
                left += 1;
                continue;
            }
            if(right == i){
                right -= 1;
                continue;
            }
            ll target = a[i]*2;
            ll sum = a[left] + a[right];
            if(sum == target){
                result += 1;
                break;
            }
            if(sum > target){
                right -= 1;
            } else{
                left += 1;
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GIFTS.INP", "r", stdin);
    freopen("GIFTS.OUT", "w", stdout);
    readData();
    ll m;
    m = gifts();
    cout << m;
    return 0;
}
