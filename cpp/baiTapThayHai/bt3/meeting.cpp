#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll n;

struct mystruct {
    ll start;
    ll finish;
    ll pos;
} a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].start >> a[i].finish;
        a[i].pos = i;
    }
}

void meeting(){
    sort(a, a+n, [](const mystruct &a, const mystruct &b){
            return a.finish < b.finish;
    });
    ll prevEnd = 0;
    vector<ll> result;
    for(int i = 0; i < n; ++i){
        if(a[i].start >= prevEnd){
            prevEnd = a[i].finish;
            result.push_back(a[i].pos+1);
        }
    }

    cout << result.size() << "\n";
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MEETING.INP", "r", stdin);
    freopen("MEETING.OUT", "w", stdout);
    readData();
    meeting();
    return 0;
}
