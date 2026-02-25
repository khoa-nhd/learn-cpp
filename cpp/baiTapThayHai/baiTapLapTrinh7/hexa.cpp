#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll gt[20] = {};
char h[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void giaiThua(){
    gt[0] = 1;
    for(int i = 1; i < 18; ++i){
        gt[i] = gt[i-1] * i;
    }
}

void hexa(){
    ll sochuso = 8;
    while(n > 15 * gt[15] / gt[15-(sochuso-1)]){
        n -= 15 * gt[15] / gt[15-(sochuso-1)];
        sochuso -= 1;
    }
    bool taken[16] = {};
    for(int i = 0; i < sochuso; ++i){
        for(int j = 15; j >= 0; --j){
            if(taken[j]) continue;
            if(i == 0 && j == 0) continue;
            ll cach = gt[16 - (i + 1)] / gt[(16 - (i + 1)) - (sochuso - 1 - i)];
            if(n <= cach){
                cout << h[j];
                taken[j] = true;
                break;
            } else{
                n -= cach;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("HEXA.INP", "r", stdin);
    freopen("HEXA.OUT", "w", stdout);
    giaiThua();
    cin >> n;
    hexa();
    return 0;
}
