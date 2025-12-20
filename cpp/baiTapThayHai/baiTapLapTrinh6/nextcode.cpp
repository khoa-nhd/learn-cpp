#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool checkNoSolution(vector<ll> &so){
    for(int i = 1; i < so.size(); ++i){
        if(so[i] > so[i-1]) return false;
    }
    return true;
}

void findNextCode(string &dict, vector<ll> &so){
//    for(int i = 0; i < so.size(); ++i){
//        cout << so[i] << " ";
//    }
//    cout << "\n";

    ll minVal = LLONG_MAX;
    ll minIdx;
    ll diemDaoNguoc;
    for(int i = so.size() - 2; i >= 0; --i){
        if(so[i] < so[i+1]){
            for(int j = i + 1; j < so.size(); ++j){
                if(minVal > so[j] && so[j] > so[i]){
                    minVal = so[j];
                    minIdx = j;
                }
            }
            swap(so[i], so[minIdx]);
            diemDaoNguoc = i;
            break;
        }
    }

    for(int i = 0; i <= diemDaoNguoc; ++i){
        cout << dict[so[i]];
    }
    for(int i = so.size() - 1; i > diemDaoNguoc; --i){
        cout << dict[so[i]];
    }
    cout << "\n";
}

void sol(string &dict){
    vector<ll> thuTu(26, 0);
    string code;
    cin >> code;

    for(int i = 0; i < dict.size(); ++i){
        int x = dict[i] - 'A';
        thuTu[x] = i;
    }

    vector<ll> so;
    for(int i = 0; i < code.size(); ++i){
        ll num = code[i] - 'A';
        so.push_back(thuTu[num]);
    }
    if(checkNoSolution(so)){
        cout << -1 << "\n";
        return;
    }
    findNextCode(dict, so);
}

int main(){
    freopen("NEXTCODE.INP", "r", stdin);
    freopen("NEXTCODE.OUT", "w", stdout);
    string s;
    while(cin >> s){
        sol(s);
    }
    return 0;
}
