#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define maxN 200005

ll n, a[maxN];
ll b[maxN];
vector<ll> dict;

bool checkdone(){
    vector<bool> co(n, false);
    for(int i = 0; i < n; ++i){
        if(i > 0){
            if(a[i] != a[i-1] && co[a[i]]) return false;
        }
        co[a[i]] = true;
    }
    return true;
}

bool sol(){
    unordered_map<ll, vector<pair<ll, ll>>> um;
    int s = 0;
    for(int i = 0; i < n; ++i){
        if(a[s] != a[i]){
            um[a[s]].push_back({s, i - 1});
            s = i;
        }
    }
    um[a[s]].push_back({s, n - 1});
    for(auto z : um){
        vector<pair<ll, ll>> x = z.second;
        if(x.size() > 1){
            if(x.size() > 4) return false;
            if(x.size() == 2){
                bool m = false, h = false, ba = false, bo = false;
                swap(a[x[0].first], a[x[1].first-1]);
                m = checkdone();
                swap(a[x[0].first], a[x[1].first-1]);
                if(x[1].second < n-1) swap(a[x[0].first], a[x[1].second+1]);
                h = checkdone();
                if(x[1].second < n-1) swap(a[x[0].first], a[x[1].second+1]);

                if(x[0].first > 0) swap(a[x[1].first], a[x[0].first-1]);
                ba = checkdone();
                if(x[0].first > 0) swap(a[x[1].first], a[x[0].first-1]);
                swap(a[x[1].first], a[x[0].second+1]);
                bo = checkdone();
                swap(a[x[1].first], a[x[0].second+1]);
                return m || h || ba || bo;
            } else{
                if(x[0].second - x[0].first + 1 > 1 &&
                   x[1].second - x[1].first + 1 > 1 &&
                   x[2].second - x[2].first + 1 > 1) return false;
                bool m = false, h = false;
                if(x[0].second - x[0].first + 1 == 1){
                    swap(a[x[0].first], a[x[1].second + 1]);
                    m = checkdone();
                    swap(a[x[0].first], a[x[1].second + 1]);
                }
                if(x[2].second - x[2].first + 1 == 1){
                    swap(a[x[2].first], a[x[1].first - 1]);
                    h = checkdone();
                    swap(a[x[2].first], a[x[1].first - 1]);
                }
                return m || h;
            }
            break;
        }
    }
    return true;
}

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> b[i];
        a[i] = b[i];
    }
    dict.clear();
    sort(b, b + n);
    dict.push_back(b[0]);
    for(int i = 1; i < n; ++i){
        if(b[i] != b[i-1]) dict.push_back(b[i]);
    }
    int limit = dict.size();
    for(int i = 0; i < n; ++i){
        int lo = 0, hi = limit;
        while(lo <= hi){
            int half = (lo + hi) / 2;
            if(dict[half] == a[i]){
                a[i] = half;
                break;
            } else if(dict[half] < a[i]) lo = half + 1;
            else hi = half - 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        bool res = sol();
        if(res) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}
