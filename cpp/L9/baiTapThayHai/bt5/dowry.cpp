#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 25

ll n, input[maxN];
ll cachChia[maxN] = {};
vector<string> res;
ll tong = 0;
ll maximum;
ll sum[4] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> input[i];
        tong += input[i];
    }
}

void updateRes(){
    string s;
    for(int i = 0; i < n; ++i){
        if(cachChia[i] == 1) s.push_back('A');
        else if(cachChia[i] == 2) s.push_back('B');
        else s.push_back('C');
    }
    res.push_back(s);
}

void downry(ll i){
    for(int v = 1; v <= 3; ++v){
        if(sum[v] + input[i] <= maximum){
            cachChia[i] = v;
            sum[v] += input[i];
            if(i == n-1 && sum[1] == sum[2] && sum[2] == sum[3]){
                updateRes();
            } else{
                downry(i+1);
            }
            sum[v] -= input[i];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DOWRY.INP", "r", stdin);
    freopen("DOWRY.OUT", "w", stdout);
    readData();
    maximum = tong/3;
    if(tong % 3 != 0){
        cout << -1;
    } else{
        downry(0);
        if(res.size() == 0) cout << -1;
        else{
            cout << res.size() << "\n";
            for(int i = 0; i < res.size(); ++i){
                cout << res[i] << "\n";
            }
        }
    }
    return 0;
}
