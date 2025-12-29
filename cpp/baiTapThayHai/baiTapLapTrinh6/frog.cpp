#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, a, b;
bool marked[maxN] = {};
vector<int> res;
ll curr;

bool valid(ll idx, bool endd){
    return (idx > 0 && idx <= n && (idx != b || endd));
}

bool valid2(ll buoc, ll e){
    if(buoc < 0){
        return (curr + buoc) >= e;
    } else{
        return (curr + buoc) <= e;
    }
}

void nhay2(ll e, bool endd){
    ll buoc = 2;
    if(curr > e) buoc = -2;
    while(curr != e){
        marked[curr] = true;
        if(valid(curr+buoc, endd) && !marked[curr+buoc] && valid2(buoc, e)){
            curr += buoc;
            res.push_back(buoc);
        } else if(valid(curr+buoc/2, endd) && !marked[curr+buoc/2] && valid2(buoc/2, e)){
            curr += buoc/2;
            res.push_back(buoc/2);
        } else{
            break;
        }
    }
    marked[curr] = true;
}

void nhay1(ll e, bool endd){
    ll buoc = 1;
    if(curr > e) buoc = -1;
    while(curr != e){
        marked[curr] = true;
        if(valid(curr+buoc, endd) && !marked[curr+buoc]){
            res.push_back(buoc);
            curr += buoc;
        } else{
            break;
        }
    }
    marked[curr] = true;
}

void frog(){
    curr = a;
    if(a == b){
        cout << 0;
        return;
    }
    if(a < b){
        nhay2(1, false);
        nhay2(a+1, false);
        nhay1(b-1, false);
        nhay2(n, false);
        nhay2(b, true);
    } else{
        nhay2(n, false);
        nhay2(a-1, false);
        nhay1(b+1, false);
        nhay2(1, false);
        nhay2(b, true);
    }
    if(res.size() != n-1 || curr != b){
        cout << 0;
    } else{
        for(int x : res){
            cout << x << "\n";
        }
    }
}

int main(){
    freopen("FROG.INP", "r", stdin);
    freopen("FROG.OUT", "w", stdout);
    cin >> n >> a >> b;
    frog();
    return 0;
}
