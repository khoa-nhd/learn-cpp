#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, x, a[maxN];
ll d[maxN];
vector<ll> f;
ll area = 0;
ll suf[maxN], pre[maxN];
ll son[maxN] = {};

void readData(){
    cin >> n >> x;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void tinhd(){
    for(int i = x-1; i < n; i += x){
        suf[i] = a[i];
        for(int j = 1; j < x; ++j){
            if(i - j + 1 < 0) break;
            suf[i-j] = min(suf[i-j+1], a[i-j]);
        }
    }
    for(int i = 0; i < n; i += x){
        pre[i] = a[i];
        for(int j = 1; j < x; ++j){
            if(i + j >= n) break;
            pre[i+j] = min(pre[i+j-1], a[i+j]);
        }
    }
    for(int i = 0; i < x; ++i){
        d[i] = min(suf[0], pre[x-1]);
    }
    for(int i = x; i < n; ++i){
        d[i] = min(suf[i-x+1], pre[i]);
    }
}

void tinhf(){
    f.push_back(x-1);
    ll curr = 0;
    for(int i = x; i < n; ++i){
        if(curr != 0 &&
           d[f[curr]] <= d[i] &&
           f[curr-1] + x >= i &&
           d[f[curr-1]] >= d[f[curr]]){
            f[curr] = i;
        } else{
            f.push_back(i);
            curr += 1;
        }
    }
}

void tinha(){
    deque<ll> dq;
    for(int i = n-1; i >= 0; --i){
        while(dq.size() > 0 && dq.front() >= i + x){
            dq.pop_front();
        }
        while(dq.size() > 0 && d[dq.back()] <= d[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        son[i] = d[dq.front()];
    }
//    for(int i = 0; i < n; ++i) cout << son[i] << " ";
    for(int i = 0; i < n; ++i){
        area += a[i] - son[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("HEDGE.INP", "r", stdin);
    freopen("HEDGE.OUT", "w", stdout);
    readData();
    tinhd();
    tinhf();
    tinha();
    cout << area << "\n" << f.size();
    return 0;
}

