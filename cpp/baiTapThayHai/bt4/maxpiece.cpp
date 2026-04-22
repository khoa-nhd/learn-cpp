#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100000

ll n, m, k;
vector<ll> catN;
vector<ll> catM;

void readData(){
    cin >> n >> m >> k;
    catN.push_back(0);
    catM.push_back(0);
    for(int i = 0; i < k; ++i){
        ll chieu, cat;
        cin >> chieu >> cat;
        if(chieu == 0){
            catN.push_back(cat);
        } else{
            catM.push_back(cat);
        }
    }
    catN.push_back(n);
    catM.push_back(m);
}

ll maxpiece(){
    ll maxCanhN = 0, maxCanhM = 0;
    sort(catN.begin(), catN.end());
    sort(catM.begin(), catM.end());
    for(int i = 1; i < catN.size(); ++i){
        maxCanhN = max(maxCanhN, catN[i] - catN[i-1]);
    }
    for(int i = 1; i < catM.size(); ++i){
        maxCanhM = max(maxCanhM, catM[i] - catM[i-1]);
    }
    return min(maxCanhM, maxCanhN);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MAXPIECE.INP", "r", stdin);
    freopen("MAXPIECE.OUT", "w", stdout);
    readData();
    ll result;
    result = maxpiece();
    cout << result;
    return 0;
}
