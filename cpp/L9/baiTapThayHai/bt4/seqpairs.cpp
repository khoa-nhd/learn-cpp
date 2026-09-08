#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll m, n, a[maxN], b[maxN];
ll prefixa[maxN] = {};
ll prefixb[maxN] = {};
vector<ll> totalSeqA;
vector<ll> totalSeqB;

void readData(){
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
}

ll seqpairs(){
    prefixa[0] = a[0];
    prefixb[0] = b[0];
    totalSeqA.push_back(a[0]);
    totalSeqB.push_back(b[0]);
    ll result = 0;
    for(int i = 1; i < m; ++i){
        prefixa[i] += prefixa[i-1] + a[i];
        totalSeqA.push_back(prefixa[i]);
    }
    for(int i = 1; i < n; ++i){
        prefixb[i] += prefixb[i-1] + b[i];
        totalSeqB.push_back(prefixb[i]);
    }

    for(int i = 1; i < m; ++i){
        for(int j = i; j < m; ++j){
            totalSeqA.push_back(prefixa[j] - prefixa[i-1]);
        }
    }
    for(int i = 1; i < n; ++i){
        for(int j = i; j < n; ++j){
            totalSeqB.push_back(prefixb[j] - prefixb[i-1]);
        }
    }

//    for(int i = 0; i < m; ++i){
//        cout << prefixa[i] << " ";
//    }
//    cout << "\n";
//    for(int i = 0; i < n; ++i){
//        cout << prefixb[i] << " ";
//    }
//    cout << "\n";
//
//    for(int i = 0; i < totalSeqA.size(); ++i){
//        cout << totalSeqA[i] << " ";
//    }
//    cout << "\n";
//    for(int i = 0; i < totalSeqB.size(); ++i){
//        cout << totalSeqB[i] << " ";
//    }

    sort(totalSeqB.begin(), totalSeqB.end());
    for(int i = 0; i < totalSeqA.size(); ++i){
        result += upper_bound(totalSeqB.begin(), totalSeqB.end(), totalSeqA[i]) - lower_bound(totalSeqB.begin(), totalSeqB.end(), totalSeqA[i]);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SEQPAIRS.INP", "r", stdin);
    freopen("SEQPAIRS.OUT", "w", stdout);
    readData();
    ll result;
    result = seqpairs();
//    cout << "\n";
    cout << result;
    return 0;
}
