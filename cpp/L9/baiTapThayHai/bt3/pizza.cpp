#include <bits/stdc++.h>
using namespace std;
#define maxN 100005
typedef long long ll;

ll n, k;

struct myStruct{
    ll sizee;
    ll cost;
    double value;
} a[maxN];

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i].sizee >> a[i].cost;
        a[i].value = (double)(a[i].sizee*a[i].sizee)/a[i].cost;
    }
}

ll pizza(){
    ll result = 0;
    sort(a, a + n, [](const myStruct &a, const myStruct &b){
         if(a.value == b.value){
            return a.cost < b.cost;
         }
         return a.value > b.value;
    });
    for(int i = 0; i < k; ++i){
        result += a[i].cost;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PIZZA.INP", "r", stdin);
    freopen("PIZZA.OUT", "w", stdout);
    readData();
    ll m;
    m = pizza();
    cout << m;
    return 0;
}
