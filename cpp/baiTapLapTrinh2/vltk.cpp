#include <bits/stdc++.h>
using namespace std;
#define maxN 50005
typedef long double ldd;
int b, k, n, m;
pair<ldd, lđ> d[maxN], p[maxN];

void readData() {
    cin >> b >> k >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> d[i].first;
        d[i].second = i + 1;
    }
    for(int i = 0; i < m; ++i){
        cin >> p[i].first;
        p[i].second = i + 1;
    }
}

void vltk() {
    sort(d, d + n, [](const pair<ldd,ldd>& a, const pair<ldd,ldd>& b) {
        return a.first > b.first;
    });
    sort(p, p + m, [](const pair<ldd,ldd>& a, const pair<ldd,ldd>& b) {
        return a.first > b.first;
    });
    vector<ldd> sumd;
    vector<ldd> sump;
    sumd.resize(n+1);
    sump.resize(m+1);
    sumd[0] = 0;
    sump[0] = 0;
    sumd[1] = d[0].first;
    sump[1] = p[0].first;
    for(int i = 2; i <= n; ++i){
        sumd[i] = sumd[i-1] + d[i-1].first;
    }
    for(int i = 2; i <= m; ++i){
        sump[i] = sump[i-1] + p[i-1].first;
    }

    int numpercent;
    int dpotion, ppotion;
    ldd current, maxx = 0;
    for(int i = 0; i <= min(n, k); ++i){
        numpercent = min(k - i, m);
        current = (b + sumd[i]) * (100 + sump[numpercent]) / 100;
        if(current > maxx || i == 0){
            dpotion = i;
            ppotion = numpercent;
            maxx = current;
        }
    }
    cout << dpotion << " " << ppotion << "\n";
    for(int i = 0; i < dpotion; ++i){
        cout << d[i].second << " ";
    }
    cout << "\n";
    for(int i = 0; i < ppotion; ++i){
        cout << p[i].second << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("VLTK.INP", "r", stdin);
    freopen("VLTK.OUT", "w", stdout);
    readData();
    vltk();
    return 0;
}
