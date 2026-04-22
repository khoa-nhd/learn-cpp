#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a[6] = {};

void readData(){
    for(int i = 0; i < 6; ++i){
        cin >> a[i];
    }
}

ll ngang(){
    ll result = LLONG_MAX;
    ll mot[26] = {};
    ll hai[26] = {};
    ll ba[26] = {};
    for(int i = 0; i <= 8; ++i){
        mot[a[0][i] - 'A'] += 1;
        mot[a[1][i] - 'A'] += 1;
        hai[a[2][i] - 'A'] += 1;
        hai[a[3][i] - 'A'] += 1;
        ba[a[4][i] - 'A'] += 1;
        ba[a[5][i] - 'A'] += 1;
    }

    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < 26; ++j){
            for(int k = 0; k < 26; ++k){
                if(i != j && j != k){
                    ll current = (18 - mot[i]) + (18 - hai[j]) + (18 - ba[k]);
                    result = min(result, current);
                }
            }
        }
    }
    return result;
}

ll doc(){
    ll result = LLONG_MAX;
    ll mot[26] = {};
    ll hai[26] = {};
    ll ba[26] = {};
    for(int i = 0; i < 6; ++i){
        mot[a[i][0] - 'A'] += 1;
        mot[a[i][1] - 'A'] += 1;
        mot[a[i][2] - 'A'] += 1;
        hai[a[i][3] - 'A'] += 1;
        hai[a[i][4] - 'A'] += 1;
        hai[a[i][5] - 'A'] += 1;
        ba[a[i][6] - 'A'] += 1;
        ba[a[i][7] - 'A'] += 1;
        ba[a[i][8] - 'A'] += 1;
    }

    for(int i = 0; i < 26; ++i){
        for(int j = 0; j < 26; ++j){
            for(int k = 0; k < 26; ++k){
                if(i != j && j != k){
                    ll current = (18 - mot[i]) + (18 - hai[j]) + (18 - ba[k]);
                    result = min(result, current);
                }
            }
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FLAG.INP", "r", stdin);
    freopen("FLAG.OUT", "w", stdout);
    readData();
    ll horizontal = ngang();
    ll vertical = doc();
    cout << min(horizontal, vertical);
    return 0;
}
