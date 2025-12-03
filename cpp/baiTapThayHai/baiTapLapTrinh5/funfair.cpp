#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n;
ll a[205][205] = {};
ll di[4] = {-1, 0, 1, 0};
ll dj[4] = {0, 1, 0, -1};

struct diem{
    ll val;
    ll x, y;
};

void readData(){
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
}

struct cmp{
    bool operator()(const diem &a, const diem &b){
        return a.val > b.val;
    }
};

bool valid(ll i, ll j){
    return (i >= 0 && j >= 0 && i < m && j < n);
}

ll multisourceDijkstra(){
    ll dist[205][205] = {};
    for(int i = 0; i < m; ++i){
        for(int j = 1; j < n; ++j){
            dist[i][j] = LLONG_MAX;
        }
    }

    priority_queue<diem, vector<diem>, cmp> pq;

    for(int i = 0; i < m; ++i){
        diem source;
        source.x = i;
        source.y = 0;
        source.val = a[i][0];
        pq.push(source);
        dist[i][0] = a[i][0];
    }

    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();

        pair<ll, ll> toaDo = {top.x, top.y};
        ll giaTri = top.val;

        if(giaTri > dist[toaDo.first][toaDo.second]) continue;

        for(int i = 0; i < 4; ++i){
            ll r = toaDo.first + di[i];
            ll c = toaDo.second + dj[i];
            ll v = a[r][c];

            if(!valid(r, c)) continue;

            if(dist[toaDo.first][toaDo.second] + v < dist[r][c]){
                dist[r][c] = dist[toaDo.first][toaDo.second] + v;
                diem temp;
                temp.x = r;
                temp.y = c;
                temp.val = dist[r][c];
                pq.push(temp);
            }
        }
    }

    ll res = LLONG_MAX;
    for(int i = 0; i < m; ++i){
        res = min(res, dist[i][n-1]);
    }
    return res;
}

//ll dijkstra(pair<ll, ll> src){ không hiệu quả
//    ll dist[205][205] = {};
//    for(int i = 0; i < m; ++i){
//        for(int j = 0; j < n; ++j){
//            dist[i][j] = LLONG_MAX;
//        }
//    }
//    dist[src.first][src.second] = a[src.first][src.second];
//
//    priority_queue<diem, vector<diem>, cmp> pq;
//    diem source;
//    source.x = src.first;
//    source.y = src.second;
//    source.val = a[src.first][src.second];
//    pq.push(source);
//    while(!pq.empty()){
//        auto top = pq.top();
//        pq.pop();
//
//        pair<ll, ll> toaDo = {top.x, top.y};
//        ll giaTri = top.val;
//
//        if(giaTri > dist[toaDo.first][toaDo.second]) continue;
//
//        for(int i = 0; i < 4; ++i){
//            ll r = toaDo.first + di[i];
//            ll c = toaDo.second + dj[i];
//            ll v = a[r][c];
//
//            if(!valid(r, c)) continue;
//
//            if(dist[toaDo.first][toaDo.second] + v < dist[r][c]){
//                dist[r][c] = dist[toaDo.first][toaDo.second] + v;
//                diem temp;
//                temp.x = r;
//                temp.y = c;
//                temp.val = dist[r][c];
//                pq.push(temp);
//            }
//        }
//    }
//
//    ll res = LLONG_MAX;
//    for(int i = 0; i < m; ++i){
//        res = min(res, dist[i][n-1]);
//    }
//    return res;
//}

int main(){
    freopen("FUNFAIR.INP", "r", stdin);
    freopen("FUNFAIR.OUT", "w", stdout);
    readData();
    ll res = LLONG_MAX;
//    for(int i = 0; i < m; ++i){
//        res = min(res, dijkstra({i, 0}));
//    }
//    cout << res;

    res = multisourceDijkstra();
    cout << res;
    return 0;
}
