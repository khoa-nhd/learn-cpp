 #include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define maxN 200005

 ll a, b, n, x[maxN];

 void readData(){
    cin >> a >> b >> n;
    for(int i = 0; i < n; ++i){
        cin >> x[i];
    }
}

ll minDist(ll curr){
    ll d = 0, c = n-1;
    ll res = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(x[half] >= curr){
            res = half;
            c = half - 1;
        } else{
            d = half + 1;
        }
    }
    if(res == 0){
        return x[0] - curr;
    } else if(res == -1){
        return curr - x[n-1];
    }
    return min(x[res] - curr, curr - x[res-1]);
}

ll portal(){
    sort(x, x + n);
    return minDist(a) + minDist(b) + 1;
}

 int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PORTAL.INP", "r", stdin);
    freopen("PORTAL.OUT", "w", stdout);
    readData();
    ll res;
    res = portal();
    cout << res;
    return 0;
}
