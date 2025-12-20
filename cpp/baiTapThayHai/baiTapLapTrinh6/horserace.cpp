#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n;
pair<ll, ll> a[maxN], b[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i].first;
        b[i].second = i + 1;
    }
}

void horserace(){
    sort(a, a + n);
    sort(b, b + n);
    ll s1 = n - 1;
    ll w1 = 0;
    ll s2 = n - 1;
    ll w2 = 0;

    for(int i = 0; i < n; ++i){
        if(a[s1].first > b[s2].first){
            cout << a[s1].second << " " << b[s2].second << "\n";
            s1 -= 1;
            s2 -= 1;
        } else if(a[w1].first > b[w2].first){
            cout << a[w1].second << " " << b[w2].second << "\n";
            w1 += 1;
            w2 += 1;
        } else{
            cout << a[w1].second << " " << b[s2].second << "\n";
            w1 += 1;
            s2 -= 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("HORSERACE.INP", "r", stdin);
    freopen("HORSERACE.OUT", "w", stdout);
    readData();
    horserace();
    return 0;
}
