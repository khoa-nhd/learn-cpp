#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
struct diem{
    double x, y;
}arr[205];
struct tron{
    double x, y, r;
};
tron ans;
bool tren[205] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> arr[i].x  >> arr[i].y;
    }
}

double dist(diem a, diem b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

bool valid(tron t){
    diem tt;
    tt.x = t.x;
    tt.y = t.y;
    for(int i = 0; i < n; ++i){
        if(dist(tt, arr[i]) > t.r && !tren[i]) return false;
    }
    return true;
}

void hai(diem a, diem b){
    tron t;
    t.r = dist(a, b) / 2;
    t.x = (a.x+b.x) / 2;
    t.y = (a.y+b.y) / 2;
    if(t.r < ans.r && valid(t)){
        ans = t;
    }
}

void ba(diem a, diem b, diem c){
    double a1, a2, b1, b2, c1, c2;
    a1 = 2*(a.x - b.x); b1 = 2*(a.y - b.y);
    c1 = a.x*a.x - b.x*b.x + a.y*a.y - b.y*b.y;
    a2 = 2*(b.x - c.x); b2 = 2*(b.y - c.y);
    c2 = b.x*b.x - c.x*c.x + b.y*b.y - c.y*c.y;
    double d = a1*b2 - a2*b1;
    if(d == 0) return;
    double dx = c1*b2 - c2*b1;
    double dy = a1*c2 - a2*c1;
    tron t;
    diem tam;
    t.x = tam.x = dx/d;
    t.y = tam.y = dy/d;
    t.r = dist(tam, a);
    if(t.r < ans.r && valid(t)){
        ans = t;
    }
}

void telecom(){
    if(n == 1){
        cout << fixed << setprecision(6) << arr[0].x << " " << arr[0].y << " " << 0.0;
        return;
    }
    ans.r = LLONG_MAX;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            tren[i] = tren[j] = true;
            hai(arr[i], arr[j]);
            tren[i] = tren[j] = false;
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            for(int k = j + 1; k < n; ++k){
                tren[i] = tren[j] = tren[k] = true;
                ba(arr[i], arr[j], arr[k]);
                tren[i] = tren[j] = tren[k] = false;
            }
        }
    }
    cout << fixed << setprecision(6) << ans.x << " " << ans.y << " " << ans.r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TELECOM.INP", "r", stdin);
    freopen("TELECOM.OUT", "w", stdout);
    readData();
    telecom();
    return 0;
}
