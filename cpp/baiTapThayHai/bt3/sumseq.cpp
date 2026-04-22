#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll n, s, a[maxN];


void readData() {
    cin >> n >> s;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void sumseq(){
    vector<ll> b;
    for(int i = 0; i < n; ++i){
        b.push_back(a[i]);
    }
    for(int i = 0; i < n; ++i){
        b.push_back(a[i]);
    }

    ll left = 0, right = 0;
    ll minLength = LLONG_MAX;
    ll start = -1;
    ll sum = a[0];
    while(right < b.size()){
        if(sum == s && (left + 1)%(n+1) >= left){
            if(minLength > right - left + 1){
                start = (left + 1)%(n+1);
                minLength = right - left + 1;
            }
            sum -= b[left];
            left += 1;
        } else if(sum > s){
            sum -= b[left];
            left += 1;
        } else{
            right += 1;
            sum += b[right];
        }

    }
    if(start == -1){
        cout << 0;
    } else {
        cout << start << " " << minLength;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUMSEQ.INP", "r", stdin);
    freopen("SUMSEQ.OUT", "w", stdout);
    readData();
    sumseq();
    return 0;
}
