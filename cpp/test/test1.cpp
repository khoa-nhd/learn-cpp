#include <bits/stdc++.h>
using namespace std;

#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)

typedef long long ll;

ll n;
vector<pair<ll, ll>> a;
pair<ll, ll> b[1000];

void readData(){
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
        //b[i].first = a[i].first;
        //b[i].second = a[i].second;
        b[i] = { a[i].first, a[i].second};
    }
}

void printArray(){
    for(int i = 0; i < n; ++i){
        cout << "(" << a[i].first << ", " << a[i].second << ") ";
    }
}

ll mahdist(){
    ll u, v;
    ll maxv = a[0].first - a[0].second;
    ll minv = maxv;
    ll maxu = a[0].first + a[0].second;
    ll minu = maxu;
    for(int i = 1; i < n; ++i){
        u = a[i].first + a[i].second;
        v = a[i].first - a[i].second;

        /*maxv = maxv < v ? v : maxv;
        minv = minv > v ? v : minv;
        maxu = maxu < u ? u : maxu;
        minu = minu > u ? u : minu;*/

        maxv = MAX(v, maxv);
        minv = MIN(v , minv);
        maxu = MAX(u, maxu);
        minu = MIN(u, minu);
    }

    printArray();
    cout << "\n";

    //sort(b, b + n, [](pair<ll,ll> i, pair<ll,ll> j) { return i.second < j.second; });
    sort(a.begin(), a.end(), [](pair<ll,ll> i, pair<ll,ll> j) {
        /*if(i.second == j.second){
          return i.first > j.first;
        }
       return i.second > j.second;*/
       /*return
        i.second > j.second
            ? true
            : (i.second == j.second ? i.first > j.first : false);*/
        return i.second == j.second ? (i.first > j.first) : (i.second > j.second);
    });

    printArray();
    cout << "\n";

    return max(abs(maxv - minv), abs(maxu - minu));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    readData();
    ll result;
    result = mahdist();
    cout << result;
    return 0;
}
