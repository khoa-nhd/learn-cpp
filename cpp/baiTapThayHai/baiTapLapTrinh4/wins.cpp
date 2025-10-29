#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll n;
struct window{
    pair<ll, ll> topLeft, bottomRight, topRight;
} a[maxN];
struct close{
    pair<ll, ll> topRight;
    ll idx;
};
vector<close> canDong;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].topLeft.first >> a[i].topLeft.second;
        cin >> a[i].bottomRight.first >> a[i].bottomRight.second;
        a[i].topRight.first = a[i].bottomRight.first;
        a[i].topRight.second = a[i].topLeft.second;
    }
}

void chePhu(ll x1, ll y1, ll x2, ll y2, ll idx){
    for(int i = 0; i < canDong.size(); ++i){
        ll a = canDong[i].topRight.first;
        ll b = canDong[i].topRight.second;
        if(x1 < a && a < x2 && y1 < b && b < y2){
            canDong.push_back({{x2, y1}, idx});
            break;
        }
    }

}

void wins(){
    canDong.push_back({a[0].topRight, 0});
    for(int i = 1; i < n; ++i){
        chePhu(a[i].topLeft.first, a[i].topLeft.second, a[i].bottomRight.first, a[i].bottomRight.second, i);
    }
    cout << canDong.size() << "\n";
    for(int i = canDong.size() - 1; i >= 0; --i){
        cout << canDong[i].idx + 1 << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("WINS.INP", "r", stdin);
    freopen("WINS.OUT", "w", stdout);
    readData();
    wins();
    return 0;
}
