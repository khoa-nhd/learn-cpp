class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       int dp[505] = {};
       int n = arr.size();
       for(int i = 1; i <= n; ++i){
            int currMax = 0;
            for(int j = i - 1; j >= i - k; --j){
                if(j >= 0){
                    currMax = max(currMax, arr[j]);
                    dp[i] = max(dp[i], dp[j] + currMax * (i - j));
                }
            }
       } 
       return dp[n];
    }
};