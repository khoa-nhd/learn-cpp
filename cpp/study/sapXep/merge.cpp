#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void nhap(vector<ll> &l, vector<ll> &r, vector<ll> &res){
    ll i = 0, j = 0;
    while(i < l.size() || j < r.size()){
        if(i < l.size() && j < r.size()){
            if(l[i] < r[j]){
                res.push_back(l[i]);
                i += 1;
            } else{
                res.push_back(r[j]);
                j += 1;
            }
        } else if(i < l.size()){
            res.push_back(l[i]);
            i += 1;
        } else{
            res.push_back(r[j]);
            j += 1;
        }
    }
}

vector<ll> mergeSort(ll d, ll c){
    vector<ll> res;
    if(d == c){
        res.push_back(a[d]);
        return res;
    }
    vector<ll> l, r;
    ll half = (d+c) / 2;
    l = mergeSort(d, half);
    r = mergeSort(half+1, c);
    nhap(l, r, res);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();
    vector<ll> res;
    res = mergeSort(0, n-1);
    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
    }
    return 0;
}
