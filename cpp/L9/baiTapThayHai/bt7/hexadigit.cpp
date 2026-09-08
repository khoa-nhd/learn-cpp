#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
char hexa[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
ll mu16[100] = {};

char hexadigit(){
    ll sochuso = 1;
    ll soSo = 15 * mu16[sochuso-1];
    ll so = 1;
    while(n > soSo * sochuso){
        so += soSo;
        n -= sochuso * soSo;
        sochuso += 1;
        soSo = 15 * mu16[sochuso-1];
    }
    ll stt = (n-1) / sochuso;
    ll idx = (n-1) % sochuso;
    so += stt;
    vector<ll> res;
    vector<char> ans;
    while(so > 0){
        res.push_back(so%16);
        so /= 16;
    }
    for(int i = 0; i < res.size(); ++i){
        ans.push_back(hexa[res[i]]);
    }
    reverse(ans.begin(), ans.end());
    return ans[idx];
}

int main(){
    freopen("HEXADIGIT.INP", "r", stdin);
    freopen("HEXADIGIT.OUT", "w", stdout);
    cin >> n;
    mu16[0] = 1;
    ll i = 1;
    while(true){
        mu16[i] = mu16[i-1] * 16;
        if(mu16[i] > 1e12) break;
        i += 1;
    }
    char res;
    res = hexadigit();
    cout << res;
    return 0;
}
