#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
string s;
ll cnt[30], cnt2[30], dd[200005];
deque<ll> dq[30];
vector<ll> mcd;
ll res = 0;

bool sub1(){
    for(int i = 1; i < n; ++i){
        if(s[i] != s[i-1]) return false;;
    }
    for(int i = n+1; i < 2 * n; ++i){
        if(s[i] != s[i-1]) return false;
    }
    return true;
}

vector<ll> inversionCount(vector<ll> v){
    if(v.size() == 1){
        return v;
    }
    vector<ll> l;
    vector<ll> r;
    for(int i = 0; i < v.size() / 2; ++i){
        l.push_back(v[i]);
    }
    for(int i = v.size() / 2; i < v.size(); ++i){
        r.push_back(v[i]);
    }
    vector<ll> re;
    l = inversionCount(l);
    r = inversionCount(r);
    ll il = 0, ir = 0;
    while(il < l.size() && ir < r.size()){
        if(l[il] < r[ir]) re.push_back(l[il++]);
        else{
            re.push_back(r[ir++]);
            res += l.size() - il;
        }
    }
    while(il < l.size()) re.push_back(l[il++]);
    while(ir < r.size()) re.push_back(r[ir++]);
    return re;
}

void sub3(){
    ll them = 0;
    for(int i = 0; i < n; ++i){
        cnt[s[i] - 'a'] += 1;
    }
    for(int i = 0; i < n; ++i){
        cnt2[s[i] - 'a'] += 1;
        if(cnt2[s[i] - 'a'] * 2 > cnt[s[i] - 'a']) dd[i] = 1;
        else dd[i] = 0;
    }
    ll pref1 = 0;
    for(int i = 0; i < n; ++i){
        if(dd[i] == 0) them += pref1;
        else pref1 += 1;
    }

    ll idx = 0;
    for(int i = 0; i < n; ++i){
        if(dd[i] == 0) dq[s[i]-'a'].push_back(idx++);
        else{
            mcd.push_back(dq[s[i]-'a'].front());
            dq[s[i]-'a'].pop_front();
        }
    }
    res += them;

    inversionCount(mcd);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    cin >> n >> s;
    n *= 2;
    sub3();
    cout << res;
    return 0;
}
