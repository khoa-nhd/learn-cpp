#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, a, b;
struct tp{
    ll x, y;
    ll pre, suf;
    ll idx;
    ll diff;
} arr[maxN];
char ans[maxN];

void readData(){
    cin >> n >> a >> b;
    for(int i = 0; i < n; ++i){
        cin >> arr[i].x;
    }
    for(int i = 0; i < n; ++i){
        cin >> arr[i].y;
    }
    for(int i = 0; i < n; ++i){
        arr[i].diff = arr[i].x - arr[i].y;
        arr[i].idx = i;
    }
}

bool cmp(tp c, tp d){
    return c.diff > d.diff;
}

void calPre(){
    arr[0].pre = arr[0].x;
    for(int i = 1; i < n; ++i){
        arr[i].pre = arr[i-1].pre + arr[i].x;
    }
    arr[n-1].suf = arr[n-1].y;
    for(int i = n-2; i >= 0; --i){
        arr[i].suf = arr[i+1].suf + arr[i].y;
    }
}

void contest(){
    sort(arr, arr+n, cmp);
    calPre();
    ll res = LLONG_MIN;
    for(int i = a-1; i+1 <= n-b; ++i){
        res = max(res, arr[i].pre + arr[i+1].suf);
    }
    for(int i = a-1; i+1 <= n-b; ++i){
        if(arr[i].pre + arr[i+1].suf == res){
            cout << res << "\n";
            for(int j = 0; j <= i; ++j){
                ans[arr[j].idx] = 'T';
            }
            for(int j = i+1; j < n; ++j){
                ans[arr[j].idx] = 'P';
            }
            for(int j = 0; j < n; ++j){
                cout << ans[j] << " ";
            }
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CONTEST.INP", "r", stdin);
    freopen("CONTEST.OUT", "w", stdout);
    readData();
    contest();
    return 0;
}
