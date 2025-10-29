#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[maxN];
vector<pair<ll, ll>> leftV, rightV;
ll leftVal[maxN] = {};
ll rightVal[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll mincost(){
    ll result = 0;
    for(int i = 0; i < n; ++i){
        if(leftV.size() != 0){
            while(leftV.size() > 0 && a[i] >= leftV.back().first){
                leftVal[leftV.back().second] = a[i];
                leftV.pop_back();
            }
        }
        leftV.push_back({a[i], i});
    }
    for(int i = n-1; i >= 0; --i){
        if(rightV.size() != 0){
            while(rightV.size() > 0 && a[i] > rightV.back().first){
                rightVal[rightV.back().second] = a[i];
                rightV.pop_back();
            }
        }
        rightV.push_back({a[i], i});
    }
    for(int i = 0; i < leftV.size(); ++i){
        leftVal[leftV[i].second] = -1;
    }
    for(int i = 0; i < rightV.size(); ++i){
        rightVal[rightV[i].second] = -1;
    }

    for(int i = 0; i < n; ++i){
        if(leftVal[i] != -1 && rightVal[i] != -1){
            result += min(leftVal[i], rightVal[i]);
        } else{
            if(leftVal[i] != -1){
                result += leftVal[i];
            } else if(rightVal[i] != -1){
                result += rightVal[i];
            }
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MINCOST.INP", "r", stdin);
    freopen("MINCOST.OUT", "w", stdout);
    readData();
    ll result;
    result = mincost();
    cout << result;
    return 0;
}
