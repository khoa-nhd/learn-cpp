#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll n;
string a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

bool sortstr(string a, string b){
    return a+b > b+a;
}

void maxnum(){
    sort(a, a + n, sortstr);
    for(int i = 0; i < n; ++i){
        cout << a[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MAXNUM.INP", "r", stdin);
    freopen("MAXNUM.OUT", "w", stdout);
    readData();
    maxnum();
    return 0;
}
