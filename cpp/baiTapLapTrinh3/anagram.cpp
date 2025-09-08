#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll anagram(){
    string a;
    cin >> a;
    if(a.size() % 2 != 0) {
        return -1;
    }
    ll nuaDau[26] = {}, nuaCuoi[26] = {};
    ll doDai = a.size();
    ll result = 0;
    for(int i = 0; i < doDai/2; ++i){
        nuaDau[(int)a[i] - 97] += 1;
    }
    for(int i = doDai/2; i < doDai; ++i){
        nuaCuoi[(int)a[i] - 97] += 1;
    }
    for(int i = 0; i < 26; ++i){
        result += abs(nuaDau[i] - nuaCuoi[i]);
    }
    result /= 2;
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ANAGRAM.INP", "r", stdin);
    freopen("ANAGRAM.OUT", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        ll m;
        m = anagram();
        cout << m << "\n";
    }
    return 0;
}
