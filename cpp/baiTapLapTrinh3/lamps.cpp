#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll lamps(){
    bool thay = false;
    ll result = -1;
    ll current = 1;
    ll prev;
    ll giatrisosanh = a[0];
    for(int i = 1; i < n; ++i){
        if(giatrisosanh == a[i]){
            current += 1;
        } else{
            if(!thay){
                current += 1;
                thay = true;
                prev = i;
            } else{
                current = 1;
                thay = false;
                i = prev;
                giatrisosanh = a[i];
            }
        }
        result = max(result, current);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    freopen("LAMPS.INP", "r", stdin);
    freopen("LAMPS.OUT", "w", stdout);
    readData();
    ll m;
    m = lamps();
    cout << m;
    return 0;
}
