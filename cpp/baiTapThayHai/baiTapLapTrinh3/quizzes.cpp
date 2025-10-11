#include <bits/stdc++.h>
using namespace std;
#define maxN 100005
typedef long long ll;

ll a[maxN];

bool check(int n, int k){
    vector<ll> b;
    for(int i = 0; i <= n; ++i){
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    ll tongday = 0;
    for(int i = 0; i <= n; ++i){
        if(b[i] > tongday + 1){
            return false;
        } else{
            tongday += b[i];
        }
        if(tongday >= k){
            return true;
        }
    }
    return false;
}

ll quizzes(){
    ll n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int low = 0, high = n - 1;
    ll result = -1;
    while(low <= high){
        int half = (low+high)/2;
        if(check(half , k)){
            high =  half - 1;
            result = half+1;
        } else{
            low =  half + 1;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("QUIZZES.INP", "r", stdin);
    freopen("QUIZZES.OUT", "w", stdout);
    ll soTest, result;
    cin >> soTest;
    for(int i = 0; i < soTest; ++i){
        result = quizzes();
        cout << result << "\n";
    }
    return 0;
}
