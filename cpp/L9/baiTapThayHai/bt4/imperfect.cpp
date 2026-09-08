#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10000005

ll a, b;
ll tongUoc[maxN] = {};

void sangTongUoc(){
    ll loop = sqrt(maxN);
    for(int i = 1; i <= loop; ++i){
        tongUoc[i*i] += i;
        for(int j = i + 1; j <= (maxN - 1)/i; ++j){
            tongUoc[i*j] += i + j;
        }
    }
}

ll imperfect(){
    ll res = 0;
    for(int i = a; i <= b; ++i){
        res += abs(i - (tongUoc[i] - i));
//        cout << tongUoc[i] << " ";
    }
//    cout << "\n";
    return res;
}

int main(){
    freopen("IMPERFECT.INP", "r", stdin);
    freopen("IMPERFECT.OUT", "w", stdout);
    cin >> a >> b;
    sangTongUoc();
    ll res;
    res = imperfect();
    cout << res;
    return 0;
}
