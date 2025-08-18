#include <bits/stdc++.h>
using namespace std;

void canarium(long long n){
    long long x = 1, y, fx = -1, fy = -1;
    long long minn = -1;
    int loop = sqrt(n*2);
    while(x < loop){
        if( (2*n - x - 1) % (2*x + 1) == 0 ){
            y = (2*n - x - 1) / (2*x + 1);
            if(abs(x-y) < minn || minn == -1){
                fx = x;
                fy = y;
                minn = abs(x-y);
            }
        }
        x += 1;
    }
    cout << fx << " " << fy << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CANARIUM.INP", "r", stdin);
    freopen("CANARIUM.OUT", "w", stdout);
    long long n;
    while (cin >> n){
        canarium(n);
    }
    return 0;
}
