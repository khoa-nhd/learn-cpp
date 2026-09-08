#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, s;
pair<ll, ll> a[maxN];

struct cap{
    ll val, idx1, idx2;
};

vector<cap> loc;

void readData(){
    cin >> n >> s;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
}

void chonCap(){
    for(int i = 1; i < n; ++i){
        while(i < n && a[i].first == a[i-1].first){
            cap temp;
            temp.val = a[i].first;
            temp.idx1 = a[i-1].second;
            temp.idx2 = a[i].second;
            loc.push_back(temp);
            i += 2;
        }
    }
//    for(cap x : loc){
//        cout << x.val << " " << x.idx1 << " " << x.idx2 << "\n";
//    }
}

void sticks(){
    sort(a, a + n);
    chonCap();
    vector<ll> ans;
    ll maxx = -1;
    ll l = 0;
    ll r = loc.size()-1;
    for(l; l < loc.size() && l < r; ++l){
        while(l < r && loc[r].val  > s / loc[l].val){
            r -= 1;
        }
        if(l >= r) break;
        ll newr = r;
        while(l < newr-1 && loc[newr-1].val == loc[newr].val) newr -= 1;
        ll curr = loc[newr].val * loc[l].val;
        vector<ll> currIdx = {loc[l].idx1, loc[l].idx2, loc[newr].idx1, loc[newr].idx2};
        sort(currIdx.begin(), currIdx.end());
        if(curr > maxx){
            maxx = curr;
            ans = currIdx;
        } else if(curr == maxx){
            if(currIdx < ans) ans = currIdx;
        }
    }

    if(maxx == -1) cout << -1;
    else{
        for(int i = 0; i < 4; ++i){
            cout << ans[i] + 1 << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("STICKS.INP", "r", stdin);
    freopen("STICKS.OUT", "w", stdout);
    readData();
    sticks();
    return 0;
}

