#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n;
ll tongdaya;
vector<pair<ll, ll>> loigiaib, loigiaic;

struct happinessRate{
    ll a;
    ll b;
    ll c;
} input[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> input[i].a >> input[i].b >> input[i].c;
        tongdaya += input[i].a;
        loigiaib.push_back({abs(input[i].b - input[i].a), i});
        loigiaic.push_back({abs(input[i].c - input[i].a), i});
    }
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

void cinema(){
    sort(loigiaib.begin(), loigiaib.end(), cmp);
    sort(loigiaic.begin(), loigiaic.end(), cmp);
    if(loigiaib[0].second != loigiaic[0].second){
        cout << tongdaya + loigiaib[0].first + loigiaic[0].first << "\n";
        cout << loigiaib[0].second + 1 << " " << loigiaic[0].second + 1;
    } else{
        if(loigiaib[0].first > loigiaic[0].first){
            cout << tongdaya + loigiaib[0].first + loigiaic[1].first << "\n";
            cout << loigiaib[0].second + 1 << " " << loigiaic[1].second + 1;
        } else{
            cout << tongdaya + loigiaib[1].first + loigiaic[0].first << "\n";
            cout << loigiaib[1].second + 1 << " " << loigiaic[0].second + 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CINEMA.INP", "r", stdin);
    freopen("CINEMA.OUT", "w", stdout);
    readData();
    cinema();
    return 0;
}
