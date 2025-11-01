#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10000005

ll a, b;
ll tongUoc[maxN] = {};

void sangTongUoc(){
    for(int i = 1; i < maxN; ++i){
        for(int j = i + i; j < maxN; j += i){
            tongUoc[j] += i;
        }
    }
}

ll imperfect(){
    ll res = 0;
    for(int i = a; i <= b; ++i){
        res += abs(i - tongUoc[i]);
//        cout << tongUoc[i] << " ";
    }
//    cout << "\n";
    return res;
}

int main(){
    freopen("PP.INP", "r", stdin);
    freopen("PP.OUT", "w", stdout);
    cin >> a >> b;
    sangTongUoc();
    ll res;
    res = imperfect();
    cout << res;
    return 0;
}
