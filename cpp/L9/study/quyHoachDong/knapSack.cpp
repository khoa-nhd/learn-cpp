#include <bits/stdc++.h>
using namespace std;

#define MAX_COL 1000

int object;
int value[1005], weight[1005];
int capacity;
int n,x;
int h[10000], p[10000];
int knapsack(){
    int dp[object + 1][capacity + 1] = {0};
    for(int i = 1; i <= object; ++i){
        for(int j = 1; j <= capacity; ++j){
            dp[i][j] = dp[i-1][j];
            if(weight[i-1] <= j){
                dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i-1]] + value[i-1]);
            }
        }
    }
    return dp[object][capacity];
}

void book(){
    vector<vector<int>> dp(n, vector(n,0));
    for(int i = 1; i < n ; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = dp[i - 1][j];
            if(p[i - 1] <= j)
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i-1]] + value[i-1]);
            }
        }
    }

}

int main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    return 0;
}
