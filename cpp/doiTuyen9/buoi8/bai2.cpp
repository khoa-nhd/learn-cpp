#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 205

vector<int> a[maxN][maxN];
vector<int> dp[maxN][maxN];
ll m, n;

void readData(){
    cin >> m >> n;
    for(int i = 0; i < maxN; ++i){
        for(int j = 0; j < maxN; ++j){
            dp[i][j].push_back(1);
        }
    }
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            string temp;
            cin >> temp;
            reverse(temp.begin(), temp.end());
            for(char x : temp) a[i][j].push_back(x - '0');
        }
    }
}

int cmp(vector<int> &x, vector<int> &y){
    if(x.size() > y.size()) return 1;
    if(x.size() < y.size()) return -1;
    for(int i = x.size() - 1; i >= 0; --i){
        if(x[i] > y[i]) return 1;
        if(x[i] < y[i]) return -1;
    }
    return 0;
}

vector<int> operator + (vector<int> x, vector<int> y){
    int i = 0, j = 0, cr = 0;
    vector<int> res;
    while(i < x.size() || j < y.size()){
        if(i < x.size()){
            cr += x[i];
            i += 1;
        }
        if(j < y.size()){
            cr += y[j];
            j += 1;
        }
        res.push_back(cr % 2);
        cr /= 2;
    }
    while(cr > 0){
        res.push_back(cr % 2);
        cr /= 2;
    }
    return res;
}

vector<int> operator * (vector<int> x, int y){
    vector<int> res;
    int cr = 0;
    for(int i = 0; i < x.size(); ++i){
        cr += x[i] * y;
        res.push_back(cr % 2);
        cr /= 2;
    }
    while(cr > 0){
        res.push_back(cr % 2);
        cr /= 2;
    }
    return res;
}

vector<int> mul10(vector<int> x, int y){
    vector<int> res;
    for(int i = 0; i < y; ++i) res.push_back(0);
    for(int i = 0; i < x.size(); ++i) res.push_back(x[i]);
    return res;
}

vector<int> operator * (vector<int> x, vector<int> y){
    vector<int> res;
    for(int i = 0; i < y.size(); ++i){
        vector<int> c = x * y[i];
        c = mul10(c, i);
        res = res + c;
    }
    return res;
}

void sol(){
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            for(int k = -1; k <= 1; ++k){
                vector<int> moi;
                moi = dp[i-1][j+k] * a[i][j];
                if(cmp(moi, dp[i][j]) == 1){
                    dp[i][j] = moi;
                }
            }
//            for(int k = dp[i][j].size() - 1; k >= 0; --k){
//                cout << dp[i][j][k];
//            }
//            cout << " ";
        }
//        cout << "\n";
    }
    vector<int> res;
    for(int j = 1; j <= n; ++j){
        if(cmp(res, dp[m][j]) == -1){
            res = dp[m][j];
        }
    }
    reverse(res.begin(), res.end());
    for(int x : res) cout << x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
