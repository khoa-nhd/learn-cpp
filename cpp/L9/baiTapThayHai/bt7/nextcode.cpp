#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string dict;
string code;
ll bang[26] = {};

void nextcode(){
    if(dict.size() == 1){
        cout << -1 << "\n";
        return;
    }
    vector<ll> c;
    for(int i = 0; i < dict.size(); ++i){
        bang[dict[i] - 'A'] = i;
    }
    for(int i = 0; i < code.size(); ++i){
        c.push_back(bang[code[i] - 'A']);
//        cout << c[i] << " ";
    }
//    cout << "\n";
    for(int i = 1; i < c.size(); ++i){
        if(c[i] > c[i-1]) break;
        if(i == c.size() - 1){
            cout << -1 << "\n";
            return;
        }
    }
     for(int i = c.size() - 2; i >= 0; --i){
        if(c[i] < c[i+1]){
            ll minval = LLONG_MAX;
            ll minidx = -1;
            for(int j = i + 1; j < c.size(); ++j){
                if(c[j] > c[i] && minval > c[j]){
                    minval = c[j];
                    minidx = j;
                }
            }
            swap(c[i], c[minidx]);
            sort(c.begin() + i + 1, c.end());
            break;
        }
     }
//     for(int x : c){
//        cout << x << " ";
//     }
//     cout << "\n";
     for(int i = 0; i < c.size(); ++i){
        cout << dict[c[i]];
     }
     cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("NEXTCODE.INP", "r", stdin);
    freopen("NEXTCODE.OUT", "w", stdout);
    while(cin >> dict){
        cin >> code;
        nextcode();
    }
    return 0;
}
