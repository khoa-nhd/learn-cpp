#include <bits/stdc++.h>
using namespace std;

#define MAX_COL 1000

const int object = 5;
int value[] = {2, 2, 4, 5, 3}, weight[] = {3, 1, 3, 4, 2};
const int capacity = 7;

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

int main(){
    int m;
    m = knapsack();
    cout << m;
    return 0;
}
