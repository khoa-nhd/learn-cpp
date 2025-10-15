#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n;
pair<ll, ll> a[maxN] = {};
char huong = 'd';
ll result = 0;

void readData(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

void checkDiDong(ll x1, ll y1, ll x2, ll y2){
    if(x2 < x1){
        huong = 't';
    } else if(y2 > y1){
        huong = 'b';
    } else if(y2 < y1){
        result += 1;
        huong = 'n';
    }
}

void checkDiTay(ll x1, ll y1, ll x2, ll y2){
    if(x2 > x1){
        huong = 'd';
    } else if(y2 < y1){
        huong = 'n';
    } else if(y2 > y1){
        result += 1;
        huong = 'b';
    }
}

void checkDiNam(ll x1, ll y1, ll x2, ll y2){
    if(y2 > y1){
        huong = 'b';
    } else if(x2 > x1){
        huong = 'd';
    } else if(x2 < x1){
        huong = 't';
        result += 1;
    }
}

void checkDiBac(ll x1, ll y1, ll x2, ll y2){
    if(y2 < y1){
        huong = 'n';
    } else if(x2 > x1){
        huong = 'd';
        result += 1;
    } else if(x2 < x1){
        huong = 't';
    }
}

void robot(){
    for(int i = 1; i <= n; ++i){
        if(huong == 'd'){
            checkDiDong(a[i-1].first, a[i-1].second, a[i].first, a[i].second);
        } else if(huong == 't'){
            checkDiTay(a[i-1].first, a[i-1].second, a[i].first, a[i].second);
        } else if(huong == 'n'){
            checkDiNam(a[i-1].first, a[i-1].second, a[i].first, a[i].second);
        } else{
            checkDiBac(a[i-1].first, a[i-1].second, a[i].first, a[i].second);
        }
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    readData();
    robot();
    return 0;
}
