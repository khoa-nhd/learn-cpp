#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a;

void readData(){
    ll n;
    while(cin >> n){
        a.push_back(n);
    }
}

void jfs(){
    vector<int> position;
    vector<int> result;
    for(int i = a.size()-1; i >= 0; --i){
        while(position.size() > 0){
            if(a[position.back()] > a[i]){
                result.push_back(position.back()+1);
                break;
            } else{
                position.pop_back();
            }
        }
        if(position.size() == 0){
            result.push_back(-1);
        }
        position.push_back(i);
    }

    for(int i = result.size()-1; i >= 0; --i){
        cout << result[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("JFS.INP", "r", stdin);
    freopen("JFS.OUT", "w", stdout);
    readData();
    jfs();
    return 0;
}
