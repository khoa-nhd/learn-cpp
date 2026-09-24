#include <bits/stdc++.h>
using namespace std;

double dist(pair<double, double> x, pair<double, double> y){
    return sqrt((x.first-y.first)*(x.first-y.first) + (x.second-y.second)*(x.second-y.second));
}

bool solve(){
    vector<pair<double, double>> v;
    vector<double> d;
    pair<double, double> tt = {};
    for(int i = 0; i < 6; ++i){
        double x, y;
        cin >> x >> y;
        v.push_back({x, y});
        tt.first += x;
        tt.second += y;
    }
    for(int i = 0; i < 6; ++i){
        for(int j = i + 1; j < 6; ++j){
            d.push_back(dist(v[i], v[j]));
        }
    }
    sort(d.begin(), d.end());
    double a = d[0];
    bool ok = true;
    for(int i = 0; i < 6 && ok; ++i) if(fabs(d[i] - a) > 1e-5) ok = false;
    for(int i = 6; i < 12 && ok; ++i) if(fabs(d[i] - a * sqrt(3.0)) > 1e-5) ok = false;
    for(int i = 12; i < 15 && ok; ++i) if(fabs(d[i] - 2 * a) > 1e-5) ok = false;
    return ok;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("HEXAGONS.INP", "r", stdin);
    freopen("HEXAGONS.OUT", "w", stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        if(solve()) cout << "Y";
        else cout << "N";
    }
    return 0;
}
