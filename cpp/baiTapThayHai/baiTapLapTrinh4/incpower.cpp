#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, p, d, a[maxN];

void readData(){
    cin >> p >> n >> d;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

double incpower(){
    sort(a, a + n);
    double result = p;
    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < n; ++i){
        cout << result * a[i] / 100.0 << " ";
        if(result * a[i] / 100.0 < d){
            result += d;
        } else{
            result += result * a[i] / 100.0;
        }
    }
    cout << "\n";
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("INCPOWER.INP", "r", stdin);
    freopen("INCPOWER.OUT", "w", stdout);
    readData();
    double result;
    result = incpower();
    cout << fixed << setprecision(6) << result;
    return 0;
}
