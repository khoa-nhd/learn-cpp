#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll n;
struct diem{
    ld x, y;
}arr[205];
struct tron{
    ld x, y, r;
};
tron ans;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> arr[i].x  >> arr[i].y;
    }
}

ld dist(diem a, diem b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

ld distmu2(diem a, diem b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

void update(ld x, ld y){
    ld maxR = 0;
    for(int i = 0; i < n; ++i){
        ld r = distmu2({x, y}, arr[i]);
        maxR = max(maxR, r);
    }
    if(maxR < ans.r*ans.r){
        ld curr = sqrt(maxR);
        ans = {x, y, curr};
    }
}

void hai(diem a, diem b){
    ld x = (a.x+b.x) / 2.0;
    ld y = (a.y+b.y) / 2.0;
    update(x, y);
}

void ba(diem a, diem b, diem c){
    ld a1, a2, b1, b2, c1, c2;
    a1 = 2*(a.x - b.x); b1 = 2*(a.y - b.y);
    c1 = a.x*a.x - b.x*b.x + a.y*a.y - b.y*b.y;
    a2 = 2*(b.x - c.x); b2 = 2*(b.y - c.y);
    c2 = b.x*b.x - c.x*c.x + b.y*b.y - c.y*c.y;
    ld d = a1*b2 - a2*b1;
    if(d == 0) return;
    ld dx = c1*b2 - c2*b1;
    ld dy = a1*c2 - a2*c1;
    ld x = dx/d;
    ld y = dy/d;
    update(x, y);
}

void telecom(){
    if(n == 1){
        cout << fixed << setprecision(6) << arr[0].x << " " << arr[0].y << " " << 0.0;
        return;
    }
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            hai(arr[i], arr[j]);
        }
    }
    ans.r = 1e18;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            for(int k = j + 1; k < n; ++k){
                ba(arr[i], arr[j], arr[k]);
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
